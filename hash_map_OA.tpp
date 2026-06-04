#pragma once
#include "hash_map_OA.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template <typename T>
HashMapOA<T>::HashMapOA(bool probeType){
    this->probeType = probeType;
    HashTable.resize(23);
    size = 0;
    capacity = 23;
}

template <typename T> 
bool HashMapOA<T>::insert(int key, const T& value){
    //rehash when loading factor > 0.7
    if(getLoadFactor() > 0.7) 
        rehash();
    //keeps track of the first index that has status deleted, we will insert here if we continue probing and we meet no duplicate keys as the one trying to be inserted
    int firstDeleted = -1;

    for (int i = 0; i < capacity; i++) {
        //depending on probe type, do linear or quadratic hash
        int index = (probeType) 
            ? (computeHash(key) + (int)pow(i, 2)) % capacity
            : computeHash(key + i); 

        if (HashTable.at(index).status == Status::occupied) {
            if (HashTable.at(index).key == key) {
                return false; // duplicate key found
            }
            continue; // keep probing
        }

        if (HashTable.at(index).status == Status::deleted) {
            // remember, but keep searching, because there may because same key can exist in later index, so we also have to check those to see if we have a duplicate or we reached an empty idex
            if (firstDeleted == -1) firstDeleted = index; 
            continue;
        }

        // if we reached a Status::empty => key is definitely not later in chain, just insert here or if we had a saved index from first delted, do that instead
        int target = (firstDeleted != -1) ? firstDeleted : index;
        HashTable.at(target) = KVPair<T>{key, value, Status::occupied};
        size++;
        return true;
    }

    // Here we have cycled through the whole hash table: use remembered tombstone if we saw one, all were occupied and none were duplicates
    if (firstDeleted != -1) {
        HashTable.at(firstDeleted) = KVPair<T>{key, value, Status::occupied};
        size++;
        return true;
    }

    return false; // table full, no slot available
}

template <typename T>
bool HashMapOA<T>::get(int key, T& value){

    
    //if a state is deleted it does not mean it is not found, it could still be found in further indices, but if it is empty then it is definitly not found later
    for (int i = 0; i < capacity; i++) {
        int index = (probeType) 
                ? (computeHash(key) + (int)pow(i, 2)) % capacity
                : computeHash(key + i); 
        if (HashTable.at(index).status == Status::empty) {
            return false;
        }
        if (HashTable.at(index).status == Status::occupied && HashTable.at(index).key == key) {
            value = HashTable.at(index).value;
            return true;
        }
    }

    return false;
}

template <typename T>
bool HashMapOA<T>::remove(int key){
    
    for(int i = 0; i< capacity; i++){
        int index = (probeType) 
                ? (computeHash(key) + (int)pow(i, 2)) % capacity
                : computeHash(key + i); 
        if(HashTable.at(index).status == Status::empty)
            return false;
        if(HashTable.at(index).status == Status::occupied && HashTable.at(index).key == key){
            HashTable.at(index).status = Status::deleted;
            size--;
            return true;
        }
    }
    return false;
}

template <typename T>
void HashMapOA<T>::print(){
    for(int i = 0; i< capacity; i++){
        cout<<i;
        if(HashTable.at(i).status == Status::occupied)
            cout<<" Key:"<< HashTable.at(i).key<<", Value:"<<HashTable.at(i).value<<endl;
        else
            cout<<endl;
    }
}

template <typename T>
void HashMapOA<T>::clear(){
    HashTable.clear();
    HashTable.resize(capacity);
    size = 0;
}


template <typename T>
double HashMapOA<T>::getLoadFactor(){
    return static_cast<double>(size) / static_cast<double>(capacity);
}


template <typename T>
int HashMapOA<T>::computeHash(int key){
    return ((key % capacity) + capacity) % capacity; // modulo normalization to handle negative keys
}




template <typename T>
void HashMapOA<T>::rehash(){
    vector<KVPair<T>> oldTable = HashTable;
    HashTable.clear();
    capacity*=2;
    HashTable.resize(capacity);
    size = 0;
    //for every element in the old table, if there is a occupied then insert that key into our HashTable, 
    for(size_t i = 0; i < oldTable.size(); i++){
        if (oldTable.at(i).status == Status::occupied)
            insert(oldTable.at(i).key, oldTable.at(i).value);
    }

}

#pragma once
#include "hash_map_chaining.h"
#include <iostream>
using namespace std;

template <typename T>
HashMapChaining<T>::HashMapChaining(){
    // initial size 23 prime number, 
    HashTable.resize(23);
    size = 0; 
    capacity = 23;
}

template <typename T>
bool HashMapChaining<T>::insert(int key, const T& value){
     //rehash when load factor exceeds 0.75
    if(getLoadFactor() > 0.75){
        rehash();
    }
    //scan to make sure there is no node with this key
    int hashIndex = ComputeHash(key);
    for(int i = 0; i<HashTable.at(hashIndex).getLength(); i++){
        if(HashTable.at(hashIndex).at(i).key == key){
            cout<<" Key: "<<key<<" already there"<<endl;
            return false;
        }
    }
    //inset the key value pair in it's right place
    KVpair<T> keyValue = {key, value};
    HashTable.at(hashIndex).insertFront(keyValue);
    size++;
    return true;
}


template <typename T>
T HashMapChaining<T>::get(int key){
    //compute hash value index
    int index = ComputeHash(key);
    if(HashTable.at(index).getLength() == 0){
        cout<<"Key Not found!"<<endl;
        return T{};
    } 
     //traverse linked list at that hash value index until we found the key
    for(int i = 0; i < HashTable.at(index).getLength(); i++){
        if(HashTable.at(index).at(i).key == key)
            return HashTable.at(index).at(i).value;
    }

    cout<<"Key Not found!"<<endl;
    return T{};
}

template <typename T>
void HashMapChaining<T>::remove(int key){
    //compute hash value index
    int index = ComputeHash(key);
    if(HashTable.at(index).getLength() == 0){
        cout<<"Key Not found!"<<endl;
        return;
    } 
     //traverse linked list at that hash value index until we found the key
    for(int i = 0; i < HashTable.at(index).getLength(); i++){
        if(HashTable.at(index).at(i).key == key){
            HashTable.at(index).deleteAt(i);
            size--;
            return;
        }
    }

    cout<<"Key Not found!"<<endl;

}


template <typename T>
void HashMapChaining<T>::print(){
    for(int i = 0; i<capacity; i++){
        cout<<i<<" ";
        if(HashTable.at(i).getLength() == 0){
            cout<<endl;
            continue;  
        } 
        for(int j = 0; j < HashTable.at(i).getLength(); j++){
            int Key = HashTable.at(i).at(j).key;
            T Value = HashTable.at(i).at(j).value;
            cout<<"-->"<<"("<<Key<<", "<<Value<<")";
        }
        cout<<endl;
    }
}


template <typename T>
int HashMapChaining<T>::ComputeHash(int key){
    return key % capacity;
    //return ((key % capacity) + capacity) % capacity;
    //modulo normalization to handle negative keys
}

template <typename T>
double HashMapChaining<T>::getLoadFactor(){
    return (double)size / (double)capacity;

}

template <typename T>
void HashMapChaining<T>::rehash(){
    //reallocate allocate double the table size
    vector<LinkedList<KVpair<T>>> oldTable = HashTable;
    // assign the new bucket size *2
    capacity*=2;
    HashTable.clear();
    HashTable.resize(capacity);
    //insert all keys from old table to new one
    size = 0;// start back at 0 and insert will incriment to appropriate size, or else it may rehash due to having the old size value
    for(int i = 0; i<oldTable.size(); i++){
        //check if that indexs linked list is empty, if it is then continue to next index
        if(oldTable.at(i).getLength() == 0) continue;
        //for every node in that linked list, we will reinsert it into the new table
        for(int j = 0; j< oldTable.at(i).getLength(); j++){
            int Key = oldTable.at(i).at(j).key;
            T Value = oldTable.at(i).at(j).value;
            insert(Key, Value);
        }
    }
}
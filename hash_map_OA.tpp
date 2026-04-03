#pragma once
#include "hash_map_OA.h"
#include <iostream>
#include <vector>
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

    int firstDeleted = -1;

    for (int i = 0; i < capacity; i++) {
        int index = computeHash(key + i); // linear probing

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

        // if we reached here, Status::empty => key is definitely not later in chain, just insert here or if we had a saved index from first delted, do that instead
        int target = (firstDeleted != -1) ? firstDeleted : index;
        HashTable.at(target) = KVPair<T>{key, value, Status::occupied};
        size++;
        return true;
    }

    // Full probe cycle: use remembered tombstone if we saw one
    if (firstDeleted != -1) {
        HashTable.at(firstDeleted) = KVPair<T>{key, value, Status::occupied};
        size++;
        return true;
    }

    return false; // table full, no slot available
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

}
/*

Implement the Unordered_Map,

Stores Key value pairs
Keys should be integer by default and then Values can be of any type
Keys must be unique.
ex.
    2: "hello"
    2: "Bye"
Is invalid
Use modular hashing for hash funciton key % capacity
Open hashing via chaining

*/
#pragma once
#include "linked_list.h"
#include <string>
#include <vector>
using namespace std;

template<typename T>
struct KVpair{
    int key;
    T value; 
};

template <typename T>
class HashMapChaining{
public:
    HashMapChaining();//constructor
    bool insert(int key, const T& value); // should account for duplicate keys and rehashing when appropirate, returns true if inserted false if not, already there,
    T get(int key); // get a value by key, if the key is found
    void remove(int key);
    void print();// print the whole hash table with values.
    double getLoadFactor();

    //destructor
    //copy constructor
    //copy assignment

    

private:
    vector<LinkedList<KVpair<T>>> HashTable; // initial size 23 prime number, rehash when load factor exceeds 0.75
    int size; // number of keys-value pairs in table
    int capacity; // total number of buckets

    int ComputeHash(int key);
    void rehash(); // called when load factor exceeds 0.75, creates a hash table 2x the size and reinserts all key, values on the new table
    
};

#include "hash_map_chaining.tpp"
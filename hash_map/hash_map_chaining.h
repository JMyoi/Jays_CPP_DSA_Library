/*
TODO: change resize at load factor 1 instead of 0.75
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

1. Missing functions
Function	Why it matters
update(key, value) (or insert_or_assign)	This is the biggest gap. Right now there's no way to change the value of a key that's already in the map. insert rejects duplicates, so you'd have to remove and then insert.
contains(key)	The most common query. Today you have to call get with a dummy out variable.
at(key) that throws	The standard way to read a value when a missing key is a bug (see section 2).
isEmpty()	Trivial (size == 0), but almost every container has it.
keys() returning vector<int>	Right now there's no way to loop over the contents except print(). Real maps have iterators. Returning a vector of keys is the simple version.
Constructor with an initial capacity	Like unordered_map::reserve: if you know you'll store 1000 items, you can skip several rehashes.



*/
#pragma once
#include "linked_list.h"
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
    bool get(int key, T& out); // returns true if key found and writes value to out
    bool remove(int key);
    void print();// print the whole hash table with values.
    double getLoadFactor();
    void clear(); // resets table
    int getSize() { return size; } // returns active pairs count
    int getCapacity() { return capacity; } // returns table size

    

private:
    vector<LinkedList<KVpair<T>>> HashTable; // initial size 23 prime number, rehash when load factor exceeds 0.75
    int size; // number of keys-value pairs in table
    int capacity; // total number of buckets

    int ComputeHash(int key);
    void rehash(); // called when load factor exceeds 0.75, creates a hash table 2x the size and reinserts all key, values on the new table
    
};

#include "hash_map_chaining.tpp"
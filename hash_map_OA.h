/*
Implementing hash map to store key value pairs, unique keys
handle collision via open addressing, Linear probling and Quadratic probing, 
    -Can be toggled via constructor, HashMapOA<T> map(1), 0 for linear, 1 for quadratic
rehash when load factor > 0.7

*/

#pragma once
#include <vector>

using namespace std;

//For open addressing we need to keep track of the state of each Data entry, 
//so You know when to stop probing for get 
//stop at an empty slot, not at a tombstone. Tombstones mean "something was deleted here, keep going."
enum class Status {empty, occupied, deleted};

template <typename T>
struct KVPair{
    int key;
    T value;
    Status status = Status::empty;
};

template <typename T>
class HashMapOA{
public:
    HashMapOA(bool probeType = false);
    bool insert(int key, const T& vlaue); // fails if tyrying to insert duplicate key
    bool get(int key, T& value);
    bool remove(int key);// returns false if key was not found
    void print();
    void clear();
    double getLoadFactor();
    int getSize(){return size;}
    int getCapacity(){return capacity;}

private:
    vector<KVPair<T>> HashTable;
    int size;
    int capacity;
    bool probeType; // false for linear probling, true for quadratic probing

    int computeHash(int key);
    void rehash();
};

#include "hash_map_OA.tpp"

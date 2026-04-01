/*

Implement the Unordered_Map,

Stores Key value pairs
Keys should be integer by default and then Values can be of any type
Keys must be unique.
ex.
    2: "hello"
    2: "Bye"
Is invalid
Use modular hashing for hash funciton
Open hashing via chaining

*/
#include "linked_list.h"
#include <string>
#include <vector>
using namespace std;

struct KVpair{
    int key;
    string value; // value should be made generic in next iteration
};


class HashMapChaining{
public:
    HashMapChaining();//constructor
    void insert(int key, string value); // should account for duplicate keys and rehashing when appropirate
    string get(int key);
    void remove(int key);
    

private:
    vector<LinkedList<KVpair>> HashTable(23); // initial size 23 prime number, rehash when load factor exceeds 0.75
    int size; // number of keys-value pairs in table
    int capacity; // total number of buckets

};
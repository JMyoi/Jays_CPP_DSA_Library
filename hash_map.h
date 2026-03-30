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
Open Addressing via chaining

*/

#pragma once
#include <iostream>
#include <string>
using namespace std;

struct HashNode{
    int key;
    int value;
    HashNode* next;
};

class Unordered_Map{
    public:
        Unordered_Map();
        Unordered_Map(int capacity);
        ~Unordered_Map();
        Unordered_Map(const Unordered_Map& other);
        Unordered_Map& operator=(const Unordered_Map& other);
        void insert(int key, int value);
        int get(int key);
        bool contains(int key);
        int remove(int key);
        int getSize();
        void print();

    private:
        HashNode** table;
        int capacity;
        int size;

        int hash(int key);
        void copyFrom(const Unordered_Map& other);
        void clear();
};

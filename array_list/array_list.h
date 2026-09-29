#pragma once

template <typename T>
class ArrayList{
public:
    ArrayList(int capacity = 5);//two in one constructor default constructor
    ~ArrayList(); // destructor for dynamically allocated array
    ArrayList(const ArrayList& origList); // copy constructor
    ArrayList& operator=(const ArrayList& listToCopy); // copy assignment
    
    
    void append(const T& x); // add to end of list
    void insert(int index, const T& x); // add x at index, throws out_of_range if index < 0 or index > size
    void deleteAt(int index); // delete element at index, throws out_of_range if index is invalid
    bool remove(const T& element);// remove first occurance of element
    bool operator== (const ArrayList& rhs) const;
    bool operator!=(const ArrayList& rhs) const;

    const T& get(int index) const; // return element at index, throws out_of_range if index is invalid
    T& get(int index); // non-const version so elements can be modified
    void display() const;
    int getSize() const; // size of List
    int getCapacity() const;

    int linearSearch(const T& key) const; // search for element x and return the index.
    int binarySearch(const T& key, bool recVer = true) const; // toggle version iterative or recursive version, reccursive by default

private:
    T* arr;
    int capacity;
    int size; // not zero indexed, actuall size, no need to +1, so accesing arr[size] is out of bound

    int binSearch(const T& key, int low, int high) const;
    int binSearchIter(const T& key, int low, int high) const;

};

#include "array_list.tpp"
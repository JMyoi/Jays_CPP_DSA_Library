#pragma once

class ArrayList{
public:
    ArrayList(int capacity = 10);//two in one constructor default constructor
    ~ArrayList(); // destructor for dynamically allocated array
    ArrayList(const ArrayList& origList); // copy constructor
    ArrayList& operator=(const ArrayList& listToCopy); // copy assignment

    void Display();
    int Size() const; // size of List
    int Capacity() const;
    void Append(int x); // add to end of list
    bool Insert(int index, int x); // add x at index 
    void Delete(int index); // delete element at index
    int LinearSearch(int x) const; // search for element x and return the index.
    bool Get(int index, int& out) const; // return element at index
private:
    int* arr;
    int capacity;
    int size; // not zero indexed, actuall size, no need to +1, so accesing arr[size] is out of bound
};

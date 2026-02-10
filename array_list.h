#pragma once

class ArrayList{
public:
    ArrayList(int capacity = 10);//two in one constructor default constructor
    ~ArrayList(); // destructor for dynamically allocated array
    //copy assignment operator
    //copy constructor
    void Display();
    int Size(); // size of List
    int Capacity();
    void Append(int x); // add to end of list
    void Insert(int index, int x); // add x at index 
    void Delete(int index); // delete element at index
    int LinearSearch(int x); // search for element x and return the index.
    int Get(int index); // return element at index
private:
    int* arr;
    int capacity;
    int size;
};

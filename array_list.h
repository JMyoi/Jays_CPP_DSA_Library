#pragma once

class ArrayList{
public:
    ArrayList(int capacity = 10);//two in one constructor default constructor
    ~ArrayList(); // destructor for dynamically allocated array
    //copy assignment operator
    //copy constructor
    void Display();
    int Size(); // size of List
    void Append(int x); // add to end of list
    void Insert(int index, int x); // add x at index 
    void Delete(int index); // delete element at index
    int Search(int x); // search for element x and return the index.
    int Get(int index); // return element at index
    void Set(int index, int x);
private:
    int* arr;
    int capacity;
    int size;
};

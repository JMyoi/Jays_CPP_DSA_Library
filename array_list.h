#pragma once
//TODO Make the class a template
//TODO exception handle

class ArrayList{
public:
    ArrayList(int capacity = 5);//two in one constructor default constructor
    ~ArrayList(); // destructor for dynamically allocated array
    ArrayList(const ArrayList& origList); // copy constructor
    ArrayList& operator=(const ArrayList& listToCopy); // copy assignment
    
    
    void append(int x); // add to end of list
    bool insert(int index, int x); // add x at index 
    void deleteAt(int index); // delete element at index
    bool remove(int element);// remove first occurance of element
    bool operator== (const ArrayList& rhs) const;
    bool operator!=(const ArrayList& rhs) const;

    bool get(int index, int& out) const; // return element at index
    void display();
    int getSize() const; // size of List
    int getCapacity() const;

    int linearSearch(int key) const; // search for element x and return the index.
    int binarySearch(int key, bool recVer = true) const; // toggle version iterative or recursive version, reccursive by default

private:
    int* arr;
    int capacity;
    int size; // not zero indexed, actuall size, no need to +1, so accesing arr[size] is out of bound

    int binSearch(int key, int low, int high) const;
    int binSearchIter(int key, int low, int high) const;

};

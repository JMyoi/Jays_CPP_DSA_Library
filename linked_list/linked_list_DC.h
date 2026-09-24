
#pragma once
/*
Doubly Circular link list Implementation
we could make the delete and insert and at operation more efficient from 
n to n/2 by seeing if the index to inser is within range of 0-length/2 then go forwards
if it is form range length/2 - length then go backwards 
*/
template <typename T>
struct Node{
    Node<T>* prev;
    T data;
    Node<T>* next;
};

template <typename T>
class LinkedListDC{
public:
    LinkedListDC(); // 
    ~LinkedListDC();
    LinkedListDC(const LinkedListDC& origList);
    LinkedListDC& operator=(const LinkedListDC& listTocopy);
    void push_back(const T& data); 
    void push_front(const T& data); 
    bool insert(int index, const T& data); // 
    bool delete_at(int index); // 
    T at(int index); // 
    void print(); // 
    int find(const T&key);
    void clear();
    void reverse();
    int getLength(){ return length;}
    //others
    //allow for sorted insertion and merging two sorted lists?
    //have a sort funciton to sort the array
    void sort();
    bool insert_sorted();
    bool merge(const LinkedListDC<T>& listToMerge); // merge two sorted linked lists, retruns false if one of the linked lists are not sorted
private:
    Node<T>* head;
    Node<T>* tail;
    int length;

};

#include "linked_list_DC.tpp"
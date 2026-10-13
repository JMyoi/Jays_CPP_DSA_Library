#pragma once

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class LinkedList{
    public:
        //core Funtions
        LinkedList(); 
        ~LinkedList();
        LinkedList(const LinkedList& origList);
        LinkedList& operator=(const LinkedList& listToCopy);
        
        void insertFront(const T& data); 
        void push_back(const T& data);
        void insertAt(int index, const T& data); // throws out_of_range if index < 0 or index > length
        T deleteAt(int index); // throws out_of_range if index is invalid
        T at(int index); // throws out_of_range if index is invalid
        void clear();
        int find(const T& key);
        void print();
        //other 
        int getLength();
        void printRec();
        void reverse();
        void reverseRec();
        void concat(const LinkedList<T>& L);
        void merge(LinkedList<T>& other); // merge two sorted linked lists, this and other
        bool hasCycle();
        T sum();
        T max(); // throws out_of_range if list is empty

    private:
        Node<T>* head;
        int length;

        void recursivePrint(Node<T>* p);
        void revRec(Node<T>* prev, Node<T>* curr);
        int recursiveCount(Node<T>* p);
};

#include "linked_list.tpp"

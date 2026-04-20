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
        bool insertAt(int index, const T& data);
        T deleteAt(int index);
        T at(int index);
        void clear();
        int find(const T& key);
        void print();
        //other 
        int getLength();
        void reverse();
        void reverseRec();
        void printRec();
        T sum();
        T max();

    private:
        Node<T>* head;
        int length;

        void recursivePrint(Node<T>* p);
        void revRec(Node<T>* prev, Node<T>* curr);
        int recursiveCount(Node<T>* p);
};

#include "linked_list.tpp"

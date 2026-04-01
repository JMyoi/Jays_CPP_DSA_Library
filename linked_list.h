#pragma once

template <typename T>
struct Node{
    T data;
    Node<T>* next;
};

template <typename T>
class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList& origList);
        LinkedList& operator=(const LinkedList& listToCopy);
        void insertFront(const T& data);
        void insertAt(int index, const T& data);
        T deleteAt(int index);
        T at(int index);
        int find(const T& key);
        int getLength();
        void print();
        void printRec();

    private:
        Node<T>* head;
        int length;

        void recursivePrint(Node<T>* p);
        int recursiveCount(Node<T>* p);
};

#include "linked_list.tpp"

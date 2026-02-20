#pragma once


struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
        LinkedList();
        //~LinkedList();
        void insert(int data);
        //void remove(int data);
        //bool search(int data);
        //int size();
        void print();
        
    private:
        Node* head;
        int length;
}; 
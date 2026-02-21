#pragma once


struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
        LinkedList();
        //~LinkedList();
        void insertFront(int data);
        void insertAt(int index, int data);
        //void at(int index);
        //void delete(int data);
        //int search(int data);
        //int length();
        void print();
        void printRec();
        
    private:
        Node* head;
        int length;

        //helper function
        void recursivePrint(Node* p); // recursive traversal needs a public wraper funciton to call this funciton and pass in head
        int recursiveCount(Node* p);


}; 
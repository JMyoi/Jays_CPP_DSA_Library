#pragma once


struct Node{
    int data;
    Node* next;
};

class LinkedList{
    public:
        LinkedList();
        ~LinkedList();
        LinkedList(const LinkedList& origList);
        LinkedList& operator=(const LinkedList& listToCopy);
        void insertFront(int data);
        //insertBack(int data);
        void insertAt(int index, int data);
        int deleteAt(int index); // delete the node and return the value held in it.
        int at(int index);
        int find(int key); // searches for linked list if key is found then return index of that key, else -1.
        int getLength();   
        void print();
        void printRec();
        
    private:
        Node* head;
        int length;

        //helper function
        void recursivePrint(Node* p); // recursive traversal needs a public wraper funciton to call this funciton and pass in head
        int recursiveCount(Node* p);


}; 

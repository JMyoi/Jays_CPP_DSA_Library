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
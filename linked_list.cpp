#include "linked_list.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList(){
    head = nullptr;
    length = 0;
}

void LinkedList::insert(int data){
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    if(head == nullptr){ // no items then just make head point to new node
        head = newNode;
    }else{
        newNode->next = head; 
        head = newNode;
    }
}

void LinkedList::print(){
    Node* temp = head;
    while(temp != nullptr){// while temp is not nullptr, end of list we keep printing
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

void LinkedList::printRec(){
    recursivePrint(head);
    cout<<endl;
}

//helper funcitons

void LinkedList::recursivePrint(Node* p){
    if(p!=nullptr){
        cout<<p->data<<" ";
        recursivePrint(p->next);
    }

}

int LinkedList::recursiveCount(Node*p){
    if(p == nullptr)
        return 0;
    else    
        return recursiveCount(p->next)+1;

}

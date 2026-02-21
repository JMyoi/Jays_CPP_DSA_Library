#include "linked_list.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList(){
    head = nullptr;
    length = 0;
}

void LinkedList::insertFront(int data){
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

void LinkedList::insertAt(int index, int data){
    // out of range
    if (index>length){
        cout<<"trying to insert out of range\n";
        return;
    }
    //create new node
    Node* temp = new Node;
    temp->data = data;
    temp->next = nullptr;
    // front of the list index = 0
    if(index == 0){
        temp->next = head;
        head = temp;
        return;
    }
    // insert at a given position, not first index.
    Node* p = head;
    for(int i = 0; i<index-1; i++){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
    
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

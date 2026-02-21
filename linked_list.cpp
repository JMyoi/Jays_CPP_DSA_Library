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
    length++;
}

/*TODO: account for inserting at one past the last node, length = 5, insert at 6.*/
void LinkedList::insertAt(int index, int data){
    // out of range
    if (index<0 || index>length){
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
    length++;
    
}

int LinkedList::deleteAt(int index){
    if(index<0 || index>length){
        cout<<"Trying to delete out of range\n";
        return -1; // excepiton handle
    }

    //first element
    if(index == 0){
        int ret = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return ret;
        length--;
    }
    // delete at index not 0
    Node* temp = head;
    Node* prev;
    for(int i = 0; i<index; i++){
        prev = temp;
        temp = temp->next;
    }
    int ret = temp->data;
    prev->next = temp->next;
    delete temp;
    length--;
    return ret;
}

int LinkedList::at(int index){
    if(index<0 || index>length){
        cout<<"out of range access\n";
        return -1;
    }

    Node* temp = head;
    for(int i = 0; i<index; i++){
        temp = temp->next;
    }
    return temp->data;
}

int LinkedList::find(int key){
    Node* temp = head;
    int index = 0;

    while(temp!= nullptr){
        if(temp->data == key)
            return index;
        temp = temp->next;
        index++;
    }
    return -1;
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

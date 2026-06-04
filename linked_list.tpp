#pragma once
#include <iostream>

//constructor
template <typename T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    length = 0;
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T>* p = head; //p to track what to delete
    while(head){
        head = head->next;
        delete p;
        p = head;
    }
}

// copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList& origList){
    //create a new list by creating each node from the origList
    length = origList.length;
    head = nullptr; // in case original list is empty

    if (origList.head!= nullptr){
        Node<T>* p = origList.head; // p is an iterator, keeps track of nodes to copy from original linked list.
        head = new Node<T>;
        head->data = p->data;
        head->next = nullptr;// in case there is only one element in the linked list.
        Node<T>* curr = head; // keeps track of current new node created;
        Node<T>* prev = head; // keeps track of the previously created node to link to curr
        p = p->next;

        while(p!=nullptr){
            curr = new Node<T>{p->data, nullptr};
            prev->next = curr;
            prev = curr;
            p = p->next;
        }
        curr->next = nullptr; // set last element to point to null
    }
}

//copy assignment operator
template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& listToCopy){

    if(this != &listToCopy){
        //delete all nodes in current list to make space for copy. 
        Node<T>* p = head; //p to track what to delete
        while(head){
            head = head->next;
            delete p;
            p = head;
        }

        // create a new linked list copying from RHS
        length = listToCopy.length;
        head = nullptr;
        if(listToCopy.head!= nullptr){
            Node<T>* p = listToCopy.head;
            head = new Node<T>{p->data, nullptr};
            Node<T>* prev = head;
            Node<T>* curr = head;
            p = p->next;
            while(p){
                curr = new Node<T>{p->data, nullptr};
                prev->next = curr;
                prev = curr;
                p = p->next;
            }
            curr->next = nullptr;
        }
    }
    return *this;

}

template <typename T>
void LinkedList<T>::insertFront(const T& data){
    Node<T>* newNode = new Node<T>;
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
template <typename T>
bool LinkedList<T>::insertAt(int index, const T& data){
    // out of range
    if (index<0 || index>length){
        std::cout<<"trying to insert out of range\n";
        return false;
    }
    //create new node
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->next = nullptr;
    // front of the list index = 0
    if(index == 0){
        temp->next = head;
        head = temp;
        length++;
        return true;
    }
    // insert at a given position, not first index.
    Node<T>* p = head;
    for(int i = 0; i<index-1; i++){
        p = p->next;
    }
    temp->next = p->next;
    p->next = temp;
    length++;
    return true;
}

template <typename T>
void LinkedList<T>::push_back(const T& data){
    Node<T>* newNode = new Node<T>{data, nullptr};
    if(head == nullptr){
        head = newNode;
        length++;
        return;
    }
    Node<T>* p = head;
    while(p->next != nullptr){
        p = p->next;
    }
    p->next = newNode;
    length++;
}

template <typename T>
T LinkedList<T>::deleteAt(int index){
    if(index<0 || index>=length){
        std::cout<<"Trying to delete out of range\n";
        return T{};
    }
    //first element
    if(index == 0){
        T ret = head->data;
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        length--;
        return ret;
    }
    // delete at index not 0
    Node<T>* temp = head;
    Node<T>* prev = nullptr;
    for(int i = 0; i<index; i++){
        prev = temp;
        temp = temp->next;
    }
    T ret = temp->data;
    prev->next = temp->next;
    delete temp;
    length--;
    return ret;
}

template <typename T>
void LinkedList<T>::clear(){
    Node<T>* p = head; //p to track what to delete
    while(head){
        head = head->next;
        delete p;
        p = head;
    }
    head = nullptr;
    length = 0;
}

template <typename T>
T LinkedList<T>::at(int index){
    if(index<0 || index>=length){
        std::cout<<"out of range access\n";
        return T{};
    }

    Node<T>* temp = head;
    for(int i = 0; i<index; i++){
        temp = temp->next;
    }
    return temp->data;
}

template <typename T>
int LinkedList<T>::find(const T& key){
    Node<T>* temp = head;
    int index = 0;

    while(temp!= nullptr){
        if(temp->data == key)
            return index;
        temp = temp->next;
        index++;
    }
    return -1;
}


template <typename T>
void LinkedList<T>::print(){
    Node<T>* temp = head;
    while(temp != nullptr){// while temp is not nullptr, end of list we keep printing
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<std::endl;
}

template <typename T>
void LinkedList<T>::printRec(){
    recursivePrint(head);
    std::cout<<std::endl;
}

template <typename T>
int LinkedList<T>::getLength(){
    return length;
}


template <typename T>
T LinkedList<T>::sum(){
    T sum{}; 
    Node<T>* p = head;
    while(p != nullptr){
        sum = sum + p->data;
        p = p->next;
    }
    return sum;
}

template <typename T>
T LinkedList<T>::max(){
    if(head == nullptr)
        return T{};
    
    T M = head->data;
    Node<T>* p = head->next;
    while(p != nullptr){
        if(p->data > M)
            M = p->data;
        p = p->next;
    }
    return M;
}

template <typename T>
void LinkedList<T>::reverse(){
    //reverse in-place using 3 sliding pointers
    //2 is not enough because when you reverse it loses the place of the rest of the linked list.
    Node<T>* prev = nullptr;
    Node<T>* curr = head;
    Node<T>* next = nullptr;
    while(curr != nullptr){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

template <typename T>
void LinkedList<T>::reverseRec(){
    Node<T>* prev = nullptr;
    Node<T>* curr = head; 
    revRec(prev, curr);
}
template <typename T>
void LinkedList<T>::concat(const LinkedList<T>& L){
    // Create a deep copy of L, then append it to this list.
    Node<T>* nodeTracker = L.head;// keeps track of list to copys nodes as we make copy of each
    Node<T>* first = nullptr;//points to first node of the copy list.
    Node<T>* prev = nullptr;// keeps track of tail of newly created list
    Node<T>* curr = nullptr;//tracks newly created nodes
    while(nodeTracker != nullptr){
        curr = new Node<T>{nodeTracker->data, nullptr};
        if(first == nullptr){
            first = curr;
        }
        else{
            prev->next = curr;
        }
        prev = curr;
        nodeTracker = nodeTracker->next;
    }

    // Nothing to append.
    if(first == nullptr){
        return;
    }

    if(head == nullptr){
        head = first;
    }
    else{
        Node<T>* tail = head;
        while(tail->next != nullptr){
            tail = tail->next;
        }
        tail->next = first;
    }

    length += L.length;
}


//helper funcitons
template <typename T>
void LinkedList<T>::revRec(Node<T>* prev, Node<T>* curr){
    if(curr != nullptr){
        revRec(curr, curr->next);
        curr->next = prev;
    }
    else
        head = prev;
}

template <typename T>
void LinkedList<T>::recursivePrint(Node<T>* p){
    if(p!=nullptr){
        std::cout<<p->data<<" ";
        recursivePrint(p->next);
    }
}

template <typename T>
int LinkedList<T>::recursiveCount(Node<T>* p){
    if(p == nullptr)
        return 0;
    else
        return recursiveCount(p->next)+1;

}

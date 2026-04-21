#include "linked_list_DC.h"
#include <iostream>

template <typename T>
LinkedListDC<T>::LinkedListDC(){
    head = nullptr;
    tail = nullptr;
    length = 0
}

template <typename T>
bool LinkedListDC<T>::insert(int index, const T& data){
    //check in range
    if(index < 0 || index > length){
        return false;
    }
    Node<T>* p = new Node<T>{nullptr, data, nullptr};
    //case that list is empty
    if(head == nullptr){
        head = p;
        tail = p;
        p->next = p;
        p->prev = p;
        length++;
        return true;
    }
    Node<T>* curr = head;
    //for case inserting in first node
    if(index == 0){
        p->next = head;
        p->prev = tail;
        head->prev = p;
        tail->next = p;
        head = p;
        length++;
        return true;
    }
    for(int i = 0; i < index - 1; ++i){
        curr = curr->next;
    }
    p->prev = curr;
    p->next = curr->next;
    curr->next->prev = p;
    curr->next = p;
    //inserting in last node, update tail
    if(index == length)
        tail = p;
    length++;
    return true;
}


template <typename T>
bool LinkedListDC<T>::delete_at(int index){
    if(index < 0 || index >=length){
        return false;
    }
    Node<T>* curr = head;
    if(index == 0){
        //handle only one element
        if(length == 1){
            delete head;
            head = nullptr;
            tail = nullptr;
            length--;
            return true;
        }
        curr = head->next;
        curr->prev = head->prev;
        head->prev->next = curr;
        delete head;
        head = curr;
        length--;
        return true;
    }
    for(int i = 0; i < index; ++i){
        curr = curr->next;
    }
    if(index == length-1){// deleting last element have to update tail
        tail = curr->prev;
    }
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
    length--;
    return true;


}

template <typename T>
T LinkedListDC<T>::at(int index){

}

template <typename T>
void LinkedListDC<T>::print(){
    
}


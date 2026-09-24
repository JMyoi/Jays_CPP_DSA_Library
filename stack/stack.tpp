#include "stack.h"
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
Stack<T>::Stack(int size){
    if (size <= 0) {
        throw invalid_argument("Stack size must be positive");
    }
    capacity = size;
    top = -1;
    array = new T[size];
}

//destructor
template <typename T>
Stack<T>::~Stack(){
    delete[] array;
}

//copy constructor
template <typename T>
Stack<T>::Stack(const Stack& origStack){

    cout<<"copy constructor called.\n";
    capacity = origStack.capacity;
    top = origStack.top;
    //initialize it's own array in heap
    array = new T[origStack.capacity];
    // copy elements from original stack to the copy
    for(int i = 0; i<top+1; i++){
        array[i] = origStack.array[i];
    }
}

//overloaded assignment operator
template <typename T>
Stack<T>& Stack<T>::operator=(const Stack& stackToCopy){
    if(this != &stackToCopy){
        capacity = stackToCopy.capacity;
        top = stackToCopy.top;
        delete []array;
        array = new T[capacity];
        for(int i = 0; i < top+1; i++){
            array[i] = stackToCopy.array[i];
        }
    }
    return *this; // this is a poitner that points at the reference to current object, but the return type is a reference so we must dereference pointer
}

template <typename T>
void Stack<T>::push(const T& data){
    // if there is still space in the stack to push 
    if(!isFull()){ //originally top+1 < capacity
        array[++top] = data; // pre incriment will incriment first then assign to the new value.
    }
    else{// allocate new sized array x2.
        int newCapacity = capacity * 2;
        T* temp = new T[newCapacity];
        for(int i = 0; i <= top; i++){
            temp[i] = array[i];
        }
        delete[] array;
        array = temp;
        capacity = newCapacity;
        array[++top] = data;
    }
}

template <typename T>
T Stack<T>::pop(){
    // the stack is empty you cannot pop.
    if(top == -1){
        throw underflow_error("Stack is empty");
    }
    else{
        return array[top--];
    }
}

template <typename T>
const T& Stack<T>::peek() const{
    if(top!=-1){
        return array[top];
    }
    else{
        throw underflow_error("Stack is empty");
    }
} 

template <typename T>
bool Stack<T>::isEmpty() const{
    return top == -1;
}

template <typename T>
bool Stack<T>::isFull() const{
    return capacity-1 == top;
}



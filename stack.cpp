#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size){
    capacity = size;
    top = -1;
    array = new int[size];

}

void Stack::push(int data){
    // if there is still space in the stack to push 
    if(top+1 <= capacity ){
        array[++top] = data; // pre incriment will incriment first then assign to the new value.
    }
    else{// allocate new sized array, 20 more.
        int* temp = new int[capacity+20];
        for(int i = 0; i<capacity; i++){
            temp[i] = array[i];
        }
        delete array;
        array = temp;
        array[++top];
        capacity+=20;
    }
}

int Stack::pop(){
    // the stack is empty you cannot pop.
    if(top == -1){
        cout<<"stack empty cannot pop;";
        return 0; // throw expeption
    }
    else{
        top--;
        return array[top+1];
    }
}

int Stack::peek(){
    if(top!=-1){
        return array[top];
    }
    else{
        cout<<"nothing in stack";
        return -1;
    }
} 

bool Stack::isEmpty(){
    return top == -1;
}

bool Stack::isFull(){
    return capacity == top;
}

#pragma once

//dynamic array based stack
class Stack{

    private:
        int capacity;
        int top; // keeps track of the index of the top of the stack.
        int* array;
    public:
        Stack();
        void push(int data);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();  
        //copy constructor, destructor, copy assignment operator

};


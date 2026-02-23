#pragma once

//dynamic array based stack
class Stack{

    private:
        int capacity;// starting at index 0, capacity = 20 actually has 21 capacity.
        int top; // keeps track of the index of the top of the stack.
        int* array;
    public:
        Stack(int size = 100);
        void push(int data);
        int pop();
        int peek();
        bool isEmpty();
        bool isFull();  
        ~Stack();
        Stack(const Stack& origStack);
        Stack& operator=(const Stack& stackToCopy);
        //copy constructor, destructor, copy assignment operator

};

// Test bench function declarations
void StackText();
void CopyConstructorTest();
void CopyAssignmentTest();
void DestructorTest();
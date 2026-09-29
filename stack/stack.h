#pragma once

//dynamic array based stack
template <typename T>
class Stack{
public:
    Stack(int size = 10);
    ~Stack();
    Stack(const Stack& origStack);
    Stack& operator=(const Stack& stackToCopy);

    void push(const T& data);
    T pop();
    const T& peek() const;

    bool isEmpty() const {return top == -1;}
    bool isFull() const {return capacity-1 == top;}
    int size() const { return top + 1; }
private:
    int capacity;// if capacity is 20, valid indexes are 0..19
    int top; // keeps track of the index of the top of the stack.
    T* array;
    
};

#include "stack.tpp"

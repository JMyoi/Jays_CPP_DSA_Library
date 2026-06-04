#pragma once
//we back

//dynamic array based stack
template <typename T>
class Stack{
public:
    Stack(int size = 100);
    void push(const T& data);
    T pop();
    const T& peek() const;
    bool isEmpty() const;
    bool isFull() const;  
    int size() const { return top + 1; }
    ~Stack();
    Stack(const Stack& origStack);
    Stack& operator=(const Stack& stackToCopy);
private:
    int capacity;// if capacity is 20, valid indexes are 0..19
    int top; // keeps track of the index of the top of the stack.
    T* array;
    
};

#include "stack.tpp"

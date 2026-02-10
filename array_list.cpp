#include "array_list.h"
#include <iostream>
using namespace std;

ArrayList::ArrayList(int capacity){
    this->capacity = capacity;
    arr = new int[capacity];
    size = 0;
}

ArrayList::~ArrayList(){
    cout<<"destructor called\n";
    delete []arr;
}

int ArrayList::Get(int index){
    if(index<size){
      return arr[index];
    }
    else{
        cout<<"Cannot get out of range\n";
        // 
    }
}

void ArrayList::Display(){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int ArrayList::Size(){
    return size;
}
int ArrayList::Capacity(){
    return capacity;
}

void ArrayList::Append(int x){
    if(capacity>size){ //then we can append
        arr[size++] = x; // post incriement will assign arr[size] = x, then incriment size++
    }
    else{// else it is not big enough and we have to allocate a new array.
        int *temp = new int[capacity+10]; // give buffer of 10 
        //copy over all elemetns from old array to new one
        for(int i = 0; i<capacity; i++){
            temp[i] = arr[i];
        }
        capacity = capacity + 10;
        temp[size] = x;//
        size++;
        // delete old array and make arr point to the new array
        delete []arr;
        arr = temp;
    }
    
}

//capacity = 10, insert at

void ArrayList::Insert(int index, int x){
    //account for index out of range.
    // if size = capacity then not enough space to insert. 
    //update it so that it allocated space for inserting. Just like vector ADT
    if(size == capacity){
        cout<<"Array has hit it's capacity, not enough space to insert\n";
        return;
    }
    if(index>0 && index<=size){
       // shift items to the right to make space at index.
        for(int i = size; i>index; i--){
            arr[i] = arr[i-1]; 
        }
        arr[index] = x;
        size++;
    }
    else{
        cout<<"Index Out of Range!\n";
    }
    
}

void ArrayList::Delete(int index){
    //can only delete valid index, if size is 5, deleting at 5 is not valid because array are index 0, so element 5 is at index 4
    if(index>=0 && index<size){
        for(int i = index; i<size-1; i++){
            arr[i] = arr[i+1];
        }
        size--;
    }
    else{
        cout<<"Cannot delete, invalid index\n";
    }
}

int ArrayList::LinearSearch(int x){
    for(int i  = 0; i<size; i++){
        if(arr[i] == x){
            return i;
        }
    }
    return -1;
}


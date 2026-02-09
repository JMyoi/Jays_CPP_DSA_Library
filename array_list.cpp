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


void ArrayList::Insert(int index, int x){
    //accoutn for index out of range.
    
    

}



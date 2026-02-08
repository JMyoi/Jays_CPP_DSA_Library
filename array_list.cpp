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

void ArrayList::Append(int x){
    arr[size+1] = x;
    //account for hitting capacity.
}
void ArrayList::Display(){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


#include "array_list.h"
#include <iostream>
#include <stdexcept>
using namespace std;

ArrayList::ArrayList(int capacity){
    if (capacity < 0) {
        throw invalid_argument("ArrayList capacity cannot be negative");
    }
    this->capacity = capacity;
    arr = new int[capacity];
    size = 0;
}

ArrayList::~ArrayList(){
    //cout<<"destructor called\n";
    delete []arr;
}

ArrayList::ArrayList(const ArrayList& origList){
    capacity = origList.capacity;
    size = origList.size;
    arr = new int[capacity];
    for(int i = 0; i<size; i++){
        arr[i] = origList.arr[i];
    }
}

ArrayList& ArrayList::operator=(const ArrayList& listToCopy){
    if(this != &listToCopy){
        capacity = listToCopy.capacity;
        size = listToCopy.size;
        delete[] arr;
        arr = new int[capacity];
        for(int i = 0; i<size; i++){
            arr[i] = listToCopy.arr[i];
        }
    }
    return *this;
}

void ArrayList::Append(int x){
    if (size == capacity){ // allocate 2x or if capacity is 0 start at 1
        int newCapacity = (capacity == 0) ? 1 : capacity * 2;
        int* temp = new int[newCapacity];
        for (int i = 0; i < size; i++){
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
        capacity = newCapacity;
    }
    arr[size++] = x;
}


bool ArrayList::Insert(int index, int x){

    if(index < 0 || index > size){
        cout<<"Index Out of Range";
        return false;
    }
    if(size == capacity){ // reallocate bigger size
        capacity = (capacity == 0)? 1 : capacity*2;
        int* temp = new int[capacity];
        for(int i = 0; i<size; i++){// copy over old to new
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    //shift items to right ot make space for new element
    for(int i = size; i > index; i--){
        arr[i] = arr[i-1];
    }
    arr[index] = x;
    size++;
    return true;
    
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

bool ArrayList::Get(int index, int& out) const{
    if(index >= 0 && index < size){
      out = arr[index];
      return true;
    }
    else{
        cout<<"Cannot get out of range\n";
        return false;
    }
}

void ArrayList::Display(){
    for(int i = 0; i<size; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int ArrayList::Size() const{
    return size;
}
int ArrayList::Capacity() const{
    return capacity;
}

int ArrayList::LinearSearch(int key) const{
    for(int i  = 0; i<size; i++){
        if(arr[i] == key){
            return i;
        }
    }
    return -1;
}

//wraper function for the private helper
int ArrayList::binarySearch(int key, bool recVer) const{
    int index = recVer ? binSearch(key, 0, size-1) :  binSearchIter(key, 0, size-1);
    return index;
}

//recursive version
int ArrayList::binSearch(int key, int low, int high) const{
    if(high < low){ // base case
        return -1;
    }
    int mid = (low + high) / 2;
    if(arr[mid] == key) return mid;
    else if(key < arr[mid]) return binSearch(key, low, mid-1);
    else if(key > arr[mid]) return binSearch(key, mid+1, high);
}
//iterative version
int ArrayList::binSearchIter(int key, int low, int high) const{
    while(high >= low){
        int mid = (low + high) / 2;
        if(arr[mid] == key){
            return mid;
        }
        if(key < arr[mid]) high = mid - 1;
        if(key > arr[mid]) low = mid + 1;
    }   
    return -1;
}

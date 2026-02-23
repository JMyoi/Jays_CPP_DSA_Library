#include "stack.h"

Stack::Stack(){
    capacity = 20;
    top = -1;
    array = new int[20];

}

void Stack::push(int data){
    // if there is still space in the stack to push 
    if(capacity > top+1 ){
        array[++top] = data; // pre incriment will assign first then incriment
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
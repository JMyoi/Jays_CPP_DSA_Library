#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack(int size){
    capacity = size;
    top = -1;
    array = new int[size];

}

//destructor
Stack::~Stack(){
    delete[] array;
}

//copy constructor
Stack::Stack(const Stack& origStack){

    cout<<"copy constructor called.\n";
    capacity = origStack.capacity;
    top = origStack.top;
    //initialize it's own array in heap
    array = new int[origStack.capacity];
    // copy elements from original stack to the copy
    for(int i = 0; i<top+1; i++){
        array[i] = origStack.array[i];
    }
}

//overloaded assignment operator
Stack& Stack::operator=(const Stack& stackToCopy){
    cout<<"copy constructor called";
    if(this != &stackToCopy){
        capacity = stackToCopy.capacity;
        top = stackToCopy.top;
        delete []array;
        array = new int[capacity];
        for(int i = 0; i<top+1; i++){
            array[i] = stackToCopy.array[i];
        }
    }
    return *this; // this is a poitner that points at the reference to current object, but the return type is a reference so we must dereference pointer
}

void Stack::push(int data){
    // if there is still space in the stack to push 
    if(top+1 < capacity ){
        array[++top] = data; // pre incriment will incriment first then assign to the new value.
    }
    else{// allocate new sized array, 20 more.
        cout<<"Expanding stack internal array for more size\n";
        int* temp = new int[capacity+20];
        for(int i = 0; i<capacity; i++){
            temp[i] = array[i];
            cout<<"copying; "<<temp[i]<<endl;
        }
        delete array;
        array = temp;
        array[++top] = data;
        capacity+=20;
    }
}

int Stack::pop(){
    // the stack is empty you cannot pop.
    if(top == -1){
        cout<<"stack empty cannot pop;";
        return -1; // throw expeption
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
    return capacity-1 == top;
}



// test bench functions


void StackText(){
    cout << "=== STACK COMPREHENSIVE TEST BENCH ===" << endl << endl;
    
    // Test 1: Empty Stack Operations
    cout << "--- Test 1: Empty Stack ---" << endl;
    Stack S1(5);
    cout << "Stack created with capacity 5" << endl;
    cout << "isEmpty() should be 1: " << S1.isEmpty() << endl;
    cout << "isFull() should be 0: " << S1.isFull() << endl;
    cout << "Attempting peek() on empty stack: " << S1.peek() << endl;
    cout << "Attempting pop() on empty stack: " << S1.pop() << endl;
    cout << endl;
    
    // Test 2: Push Operations - Single Element
    cout << "--- Test 2: Single Element Push ---" << endl;
    S1.push(10);
    cout << "Pushed 10" << endl;
    cout << "isEmpty() should be 0: " << S1.isEmpty() << endl;
    cout << "peek() should be 10: " << S1.peek() << endl;
    cout << endl;
    
    // Test 3: Multiple Push Operations
    cout << "--- Test 3: Multiple Push Operations ---" << endl;
    S1.push(20);
    S1.push(30);
    S1.push(40);
    cout << "Pushed 20, 30, 40" << endl;
    cout << "peek() should be 40: " << S1.peek() << endl;
    cout << "isFull() should be 0: " << S1.isFull() << endl;
    cout << endl;
    
    // Test 4: Fill to Capacity
    cout << "--- Test 4: Fill to Capacity ---" << endl;
    S1.push(50);
    cout << "Pushed 50 (5th element)" << endl;
    cout << "Stack now: 10, 20, 30, 40, 50" << endl;
    cout << "isFull() should be 1: " << S1.isFull() << endl;
    cout << "peek() should be 50: " << S1.peek() << endl;
    cout << endl;
    
    // Test 5: Push Beyond Capacity (Dynamic Expansion)
    cout << "--- Test 5: Dynamic Expansion ---" << endl;
    S1.push(60);
    S1.push(70);
    cout << "Pushed 60, 70 (should trigger expansion)" << endl;
    cout << "peek() should be 70: " << S1.peek() << endl;
    cout << "isFull() should be 0: " << S1.isFull() << endl;
    cout << endl;
    
    // Test 6: Pop Operations
    cout << "--- Test 6: Pop Operations ---" << endl;
    cout << "Popping: " << S1.pop() << " (should be 70)" << endl;
    cout << "Popping: " << S1.pop() << " (should be 60)" << endl;
    cout << "peek() should be 50: " << S1.peek() << endl;
    cout << "Popping: " << S1.pop() << " (should be 50)" << endl;
    cout << "Popping: " << S1.pop() << " (should be 40)" << endl;
    cout << "peek() should be 30: " << S1.peek() << endl;
    cout << endl;
    
    // Test 7: Pop Until Empty
    cout << "--- Test 7: Pop Until Empty ---" << endl;
    cout << "Remaining elements: 10, 20, 30" << endl;
    cout << "Popping: " << S1.pop() << " (should be 30)" << endl;
    cout << "Popping: " << S1.pop() << " (should be 20)" << endl;
    cout << "Popping: " << S1.pop() << " (should be 10)" << endl;
    cout << "isEmpty() should be 1: " << S1.isEmpty() << endl;
    cout << "Attempting pop() on empty stack: " << S1.pop() << endl;
    cout << endl;
    
    // Test 8: Push After Emptying
    cout << "--- Test 8: Push After Emptying ---" << endl;
    S1.push(100);
    S1.push(200);
    cout << "Pushed 100, 200 after emptying" << endl;
    cout << "peek() should be 200: " << S1.peek() << endl;
    cout << "isEmpty() should be 0: " << S1.isEmpty() << endl;
    cout << endl;
    
    // Test 9: Mixed Operations
    cout << "--- Test 9: Mixed Push/Pop Operations ---" << endl;
    S1.push(300);
    cout << "Pushed 300, peek(): " << S1.peek() << endl;
    cout << "Popping: " << S1.pop() << endl;
    S1.push(400);
    S1.push(500);
    cout << "Pushed 400, 500" << endl;
    cout << "peek() should be 500: " << S1.peek() << endl;
    cout << "Popping: " << S1.pop() << " (should be 500)" << endl;
    cout << "Popping: " << S1.pop() << " (should be 400)" << endl;
    cout << "peek() should be 200: " << S1.peek() << endl;
    cout << endl;
    
    // Test 10: Large Capacity Stack
    cout << "--- Test 10: Large Capacity Stack ---" << endl;
    Stack S2(3);
    cout << "Created stack with capacity 3" << endl;
    S2.push(1);
    S2.push(2);
    S2.push(3);
    cout << "Pushed 1, 2, 3 - isFull(): " << S2.isFull() << endl;
    S2.push(4);
    S2.push(5);
    S2.push(6);
    S2.push(7);
    S2.push(8);
    cout << "Pushed 5 more elements (4-8)" << endl;
    cout << "peek() should be 8: " << S2.peek() << endl;
    for(int i = 0; i < 8; i++) {
        cout << "Pop " << (i+1) << ": " << S2.pop() << endl;
    }
    cout << "isEmpty() should be 1: " << S2.isEmpty() << endl;
    cout << endl;


    CopyConstructorTest();
    CopyAssignmentTest();
    DestructorTest();
    
    cout << "=== ALL TESTS COMPLETE ===" << endl;




}

void CopyConstructorTest(){
    cout << "\n=== COPY CONSTRUCTOR TEST ===" << endl << endl;
    
    // Test 1: Copy empty stack
    cout << "--- Test 1: Copy Empty Stack ---" << endl;
    Stack S1(5);
    Stack S2(S1);  // Copy constructor
    cout << "Original isEmpty(): " << S1.isEmpty() << endl;
    cout << "Copy isEmpty(): " << S2.isEmpty() << endl;
    cout << endl;
    
    // Test 2: Copy stack with elements
    cout << "--- Test 2: Copy Stack with Elements ---" << endl;
    S1.push(100);
    S1.push(200);
    S1.push(300);
    cout << "Original stack has 3 elements (100, 200, 300)" << endl;
    cout << "Original peek(): " << S1.peek() << endl;
    
    Stack S3(S1);  // Copy constructor
    cout << "Copy created" << endl;
    cout << "Copy peek(): " << S3.peek() << endl;
    cout << "Copy isEmpty(): " << S3.isEmpty() << endl;
    cout << endl;
    
    // Test 3: Verify deep copy - modify original
    cout << "--- Test 3: Deep Copy Verification (Modify Original) ---" << endl;
    cout << "Pushing 400 to original stack" << endl;
    S1.push(400);
    cout << "Original peek() should be 400: " << S1.peek() << endl;
    cout << "Copy peek() should still be 300: " << S3.peek() << endl;
    cout << endl;
    
    // Test 4: Verify deep copy - modify copy
    cout << "--- Test 4: Deep Copy Verification (Modify Copy) ---" << endl;
    cout << "Popping from copy" << endl;
    S3.pop();
    cout << "Copy peek() should be 200: " << S3.peek() << endl;
    cout << "Original peek() should still be 400: " << S1.peek() << endl;
    cout << endl;
    
    // Test 5: Copy full stack
    cout << "--- Test 5: Copy Full Stack ---" << endl;
    Stack S4(3);
    S4.push(10);
    S4.push(20);
    S4.push(30);
    cout << "Original isFull(): " << S4.isFull() << endl;
    
    Stack S5(S4);  // Copy constructor
    cout << "Copy isFull(): " << S5.isFull() << endl;
    cout << "Copy peek(): " << S5.peek() << endl;
    cout << endl;
    
    cout << "=== COPY CONSTRUCTOR TESTS COMPLETE ===" << endl;



}

void CopyAssignmentTest(){
    cout << "\n=== COPY ASSIGNMENT OPERATOR TEST ===" << endl << endl;
    
    // Test 1: Assign empty to empty
    cout << "--- Test 1: Assign Empty to Empty ---" << endl;
    Stack S1(5);
    Stack S2(10);
    S2 = S1;  // Copy assignment
    cout << "After assignment, S2 isEmpty(): " << S2.isEmpty() << endl;
    cout << endl;
    
    // Test 2: Assign non-empty to empty
    cout << "--- Test 2: Assign Non-Empty to Empty ---" << endl;
    Stack S3(5);
    S3.push(100);
    S3.push(200);
    S3.push(300);
    
    Stack S4(10);
    S4 = S3;  // Copy assignment
    cout << "S3 peek() should be 300: " << S3.peek() << endl;
    cout << "S4 peek() should be 300: " << S4.peek() << endl;
    cout << endl;
    
    // Test 3: Assign non-empty to non-empty
    cout << "--- Test 3: Assign Non-Empty to Non-Empty ---" << endl;
    Stack S5(5);
    S5.push(10);
    S5.push(20);
    
    Stack S6(5);
    S6.push(500);
    S6.push(600);
    S6.push(700);
    
    cout << "Before assignment - S5 peek(): " << S5.peek() << endl;
    cout << "Before assignment - S6 peek(): " << S6.peek() << endl;
    
    S5 = S6;  // Copy assignment
    cout << "After assignment - S5 peek() should be 700: " << S5.peek() << endl;
    cout << "After assignment - S6 peek() should be 700: " << S6.peek() << endl;
    cout << endl;
    
    // Test 4: Self-assignment
    cout << "--- Test 4: Self-Assignment ---" << endl;
    Stack S7(5);
    S7.push(100);
    S7.push(200);
    cout << "Before self-assignment peek(): " << S7.peek() << endl;
    S7 = S7;  // Self-assignment
    cout << "After self-assignment peek() should be 200: " << S7.peek() << endl;
    cout << endl;
    
    // Test 5: Verify deep copy - modify original
    cout << "--- Test 5: Deep Copy Verification (Modify Original) ---" << endl;
    Stack S8(5);
    S8.push(1);
    S8.push(2);
    S8.push(3);
    
    Stack S9(5);
    S9 = S8;  // Copy assignment
    
    cout << "Pushing 4 to S8" << endl;
    S8.push(4);
    cout << "S8 peek() should be 4: " << S8.peek() << endl;
    cout << "S9 peek() should still be 3: " << S9.peek() << endl;
    cout << endl;
    
    // Test 6: Verify deep copy - modify copy
    cout << "--- Test 6: Deep Copy Verification (Modify Copy) ---" << endl;
    cout << "Popping from S9" << endl;
    S9.pop();
    cout << "S9 peek() should be 2: " << S9.peek() << endl;
    cout << "S8 peek() should still be 4: " << S8.peek() << endl;
    cout << endl;
    
    // Test 7: Chain assignment
    cout << "--- Test 7: Chain Assignment ---" << endl;
    Stack S10(5);
    S10.push(999);
    
    Stack S11(5);
    Stack S12(5);
    
    S12 = S11 = S10;  // Chain assignment
    cout << "S10 peek(): " << S10.peek() << endl;
    cout << "S11 peek(): " << S11.peek() << endl;
    cout << "S12 peek(): " << S12.peek() << endl;
    cout << endl;
    
    cout << "=== COPY ASSIGNMENT OPERATOR TESTS COMPLETE ===" << endl;
}

void DestructorTest(){
    cout << "\n=== DESTRUCTOR TEST ===" << endl << endl;
    
    // Test 1: Destructor on empty stack
    cout << "--- Test 1: Destructor on Empty Stack ---" << endl;
    {
        Stack S1(5);
        cout << "Empty stack created in scope" << endl;
    }  // Destructor called here
    cout << "Stack destroyed (scope ended)" << endl;
    cout << endl;
    
    // Test 2: Destructor on stack with elements
    cout << "--- Test 2: Destructor on Stack with Elements ---" << endl;
    {
        Stack S2(5);
        S2.push(10);
        S2.push(20);
        S2.push(30);
        cout << "Stack with 3 elements created in scope" << endl;
        cout << "peek(): " << S2.peek() << endl;
    }  // Destructor called here
    cout << "Stack destroyed (scope ended)" << endl;
    cout << endl;
    
    // Test 3: Destructor on expanded stack
    cout << "--- Test 3: Destructor on Expanded Stack ---" << endl;
    {
        Stack S3(3);
        S3.push(1);
        S3.push(2);
        S3.push(3);
        S3.push(4);  // Triggers expansion
        S3.push(5);
        cout << "Expanded stack with 5 elements created in scope" << endl;
        cout << "peek(): " << S3.peek() << endl;
    }  // Destructor called here
    cout << "Stack destroyed (scope ended)" << endl;
    cout << endl;
    
    // Test 4: Multiple stacks destroyed
    cout << "--- Test 4: Multiple Stack Destruction ---" << endl;
    {
        Stack S4(5);
        Stack S5(10);
        Stack S6(3);
        S4.push(100);
        S5.push(200);
        S6.push(300);
        cout << "3 stacks created in scope" << endl;
    }  // All destructors called here
    cout << "All stacks destroyed (scope ended)" << endl;
    cout << endl;
    
    cout << "=== DESTRUCTOR TESTS COMPLETE ===" << endl;
}





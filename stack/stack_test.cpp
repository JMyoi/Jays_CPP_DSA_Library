#include <iostream>
#include <string>
#include <stdexcept>
#include "test_bench.h"
#include "stack.h"
using namespace std;

void StackTest(){
    cout << "=== STACK COMPREHENSIVE TEST BENCH ===" << endl << endl;

    // Test 1: Empty Stack Operations
    cout << "--- Test 1: Empty Stack ---" << endl;
    Stack<int> S1(5);
    cout << "Stack created with capacity 5" << endl;
    cout << "isEmpty() should be 1: " << S1.isEmpty() << endl;
    cout << "isFull() should be 0: " << S1.isFull() << endl;
    try {
        cout << "Attempting peek() on empty stack: " << S1.peek() << endl;
    }
    catch (const underflow_error& e) {
        cout << "Attempting peek() on empty stack threw: " << e.what() << endl;
    }
    try {
        cout << "Attempting pop() on empty stack: " << S1.pop() << endl;
    }
    catch (const underflow_error& e) {
        cout << "Attempting pop() on empty stack threw: " << e.what() << endl;
    }
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
    try {
        cout << "Attempting pop() on empty stack: " << S1.pop() << endl;
    }
    catch (const underflow_error& e) {
        cout << "Attempting pop() on empty stack threw: " << e.what() << endl;
    }
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
    Stack<int> S2(3);
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


    // Copy Constructor Tests
    cout << "\n--- Test 11: Copy Empty Stack ---" << endl;
    {
        Stack<int> A(5);
        Stack<int> B(A);
        cout << "Original isEmpty(): " << A.isEmpty() << endl;
        cout << "Copy isEmpty(): " << B.isEmpty() << endl;
    }
    cout << endl;

    cout << "--- Test 12: Copy Stack with Elements ---" << endl;
    {
        Stack<int> A(5);
        A.push(100); A.push(200); A.push(300);
        Stack<int> B(A);
        cout << "Original peek() should be 300: " << A.peek() << endl;
        cout << "Copy peek() should be 300: " << B.peek() << endl;
        A.push(400);
        cout << "After pushing 400 to original, original peek() should be 400: " << A.peek() << endl;
        cout << "Copy peek() should still be 300: " << B.peek() << endl;
        B.pop();
        cout << "After popping copy, copy peek() should be 200: " << B.peek() << endl;
        cout << "Original peek() should still be 400: " << A.peek() << endl;
    }
    cout << endl;

    cout << "--- Test 13: Copy Full Stack ---" << endl;
    {
        Stack<int> A(3);
        A.push(10); A.push(20); A.push(30);
        Stack<int> B(A);
        cout << "Original isFull() should be 1: " << A.isFull() << endl;
        cout << "Copy isFull() should be 1: " << B.isFull() << endl;
        cout << "Copy peek() should be 30: " << B.peek() << endl;
    }
    cout << endl;

    // Copy Assignment Tests
    cout << "--- Test 14: Assign Empty to Empty ---" << endl;
    {
        Stack<int> A(5), B(10);
        B = A;
        cout << "After assignment, B isEmpty() should be 1: " << B.isEmpty() << endl;
    }
    cout << endl;

    cout << "--- Test 15: Assign Non-Empty, Deep Copy Verification ---" << endl;
    {
        Stack<int> A(5);
        A.push(1); A.push(2); A.push(3);
        Stack<int> B(5);
        B = A;
        cout << "B peek() should be 3: " << B.peek() << endl;
        A.push(4);
        cout << "After pushing 4 to A, A peek() should be 4: " << A.peek() << endl;
        cout << "B peek() should still be 3: " << B.peek() << endl;
        B.pop();
        cout << "After popping B, B peek() should be 2: " << B.peek() << endl;
        cout << "A peek() should still be 4: " << A.peek() << endl;
    }
    cout << endl;

    cout << "--- Test 16: Self-Assignment ---" << endl;
    {
        Stack<int> A(5);
        A.push(100); A.push(200);
        A = A;
        cout << "After self-assignment, peek() should be 200: " << A.peek() << endl;
    }
    cout << endl;

    cout << "--- Test 17: Chain Assignment ---" << endl;
    {
        Stack<int> A(5), B(5), C(5);
        A.push(999);
        C = B = A;
        cout << "A peek() should be 999: " << A.peek() << endl;
        cout << "B peek() should be 999: " << B.peek() << endl;
        cout << "C peek() should be 999: " << C.peek() << endl;
    }
    cout << endl;

    // Destructor Tests
    cout << "--- Test 18: Destructor on Empty Stack ---" << endl;
    {
        Stack<int> A(5);
        cout << "Empty stack created in scope" << endl;
    }
    cout << "Stack destroyed (scope ended)" << endl;
    cout << endl;

    cout << "--- Test 19: Destructor on Stack with Elements ---" << endl;
    {
        Stack<int> A(5);
        A.push(10); A.push(20); A.push(30);
        cout << "peek(): " << A.peek() << endl;
    }
    cout << "Stack destroyed (scope ended)" << endl;
    cout << endl;

    cout << "--- Test 20: Destructor on Expanded Stack ---" << endl;
    {
        Stack<int> A(3);
        A.push(1); A.push(2); A.push(3); A.push(4); A.push(5);
        cout << "peek(): " << A.peek() << endl;
    }
    cout << "Expanded stack destroyed (scope ended)" << endl;
    cout << endl;

    cout << "--- Test 21: Generic Type Support (string) ---" << endl;
    {
        Stack<string> words(2);
        words.push("alpha");
        words.push("beta");
        words.push("gamma");
        cout << "Top string should be gamma: " << words.peek() << endl;
        cout << "Pop should return gamma: " << words.pop() << endl;
        cout << "Next top should be beta: " << words.peek() << endl;
        cout << "Current size should be 2: " << words.size() << endl;
    }
    cout << endl;

    cout << "=== ALL TESTS COMPLETE ===" << endl;
}

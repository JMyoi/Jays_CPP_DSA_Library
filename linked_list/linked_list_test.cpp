#include <iostream>
#include <string>
#include <stdexcept>
#include "test_bench.h"
#include "linked_list.h"
using namespace std;

void LinkedListTest(){
    cout << "=== LINKED LIST COMPREHENSIVE TEST BENCH ===" << endl << endl;

    // Test 1: Empty List Operations
    cout << "--- Test 1: Empty List ---" << endl;
    LinkedList<int> L1;
    cout << "List created" << endl;
    cout << "getLength() should be 0: " << L1.getLength() << endl;
    cout << "print() should show nothing: ";
    L1.print();
    cout << "Attempting at(0): " << L1.at(0) << endl;
    cout << "Attempting find(5): " << L1.find(5) << endl;
    cout << "Attempting deleteAt(0): " << L1.deleteAt(0) << endl;
    cout << endl;

    // Test 2: Insert Front - Single Element
    cout << "--- Test 2: Single Element Insert ---" << endl;
    L1.insertFront(10);
    cout << "Inserted 10 at front" << endl;
    cout << "List: ";
    L1.print();
    cout << "getLength() should be 1: " << L1.getLength() << endl;
    cout << "at(0) should be 10: " << L1.at(0) << endl;
    cout << endl;

    // Test 3: Insert Front - Multiple Elements
    cout << "--- Test 3: Multiple Insert Front ---" << endl;
    L1.insertFront(20);
    L1.insertFront(30);
    L1.insertFront(40);
    cout << "Inserted 20, 30, 40 at front" << endl;
    cout << "List (should be 40, 30, 20, 10): ";
    L1.print();
    cout << "getLength() should be 4: " << L1.getLength() << endl;
    cout << endl;

    // Test 4: Access Elements by Index
    cout << "--- Test 4: Access by Index ---" << endl;
    cout << "at(0) should be 40: " << L1.at(0) << endl;
    cout << "at(1) should be 30: " << L1.at(1) << endl;
    cout << "at(2) should be 20: " << L1.at(2) << endl;
    cout << "at(3) should be 10: " << L1.at(3) << endl;
    cout << "at(4) out of range: " << L1.at(4) << endl;
    cout << "at(-1) out of range: " << L1.at(-1) << endl;
    cout << endl;

    // Test 5: Find Elements
    cout << "--- Test 5: Find Elements ---" << endl;
    cout << "find(40) should be 0: " << L1.find(40) << endl;
    cout << "find(20) should be 2: " << L1.find(20) << endl;
    cout << "find(10) should be 3: " << L1.find(10) << endl;
    cout << "find(99) should be -1: " << L1.find(99) << endl;
    cout << endl;

    // Test 6: Insert At Specific Index
    cout << "--- Test 6: Insert At Index ---" << endl;
    LinkedList<int> L2;
    L2.insertAt(0, 100);  // Insert into empty list
    cout << "Inserted 100 at index 0 in empty list: ";
    L2.print();
    L2.insertAt(0, 200);  // Insert at front
    cout << "Inserted 200 at index 0: ";
    L2.print();
    L2.insertAt(2, 300);  // Insert at end
    cout << "Inserted 300 at index 2: ";
    L2.print();
    L2.insertAt(1, 150);  // Insert in middle
    cout << "Inserted 150 at index 1 (should be 200, 150, 100, 300): ";
    L2.print();
    L2.insertAt(10, 999); // Out of range
    cout << endl;

    // Test 7: Delete At Index
    cout << "--- Test 7: Delete At Index ---" << endl;
    LinkedList<int> L3;
    L3.insertFront(5);
    L3.insertFront(4);
    L3.insertFront(3);
    L3.insertFront(2);
    L3.insertFront(1);
    cout << "List before deletions: ";
    L3.print();

    cout << "deleteAt(0) should return 1: " << L3.deleteAt(0) << endl;
    cout << "List after deleting at 0: ";
    L3.print();

    cout << "deleteAt(2) should return 4: " << L3.deleteAt(2) << endl;
    cout << "List after deleting at 2: ";
    L3.print();

    cout << "deleteAt(1) should return 3: " << L3.deleteAt(1) << endl;
    cout << "List after deleting at 1: ";
    L3.print();
    cout << endl;

    // Test 8: Delete Until Empty
    cout << "--- Test 8: Delete Until Empty ---" << endl;
    cout << "Remaining elements: 2, 5" << endl;
    cout << "deleteAt(0): " << L3.deleteAt(0) << endl;
    cout << "List: ";
    L3.print();
    cout << "deleteAt(0): " << L3.deleteAt(0) << endl;
    cout << "List should be empty: ";
    L3.print();
    cout << "getLength() should be 0: " << L3.getLength() << endl;
    cout << "Attempting deleteAt(0) on empty: " << L3.deleteAt(0) << endl;
    cout << endl;

    // Test 9: Recursive Print
    cout << "--- Test 9: Recursive Print ---" << endl;
    LinkedList<int> L4;
    L4.insertFront(3);
    L4.insertFront(2);
    L4.insertFront(1);
    cout << "List with print(): ";
    L4.print();
    cout << "List with printRec(): ";
    L4.printRec();
    cout << endl;

    // Test 10: Build and Search Operations
    cout << "--- Test 10: Build and Search ---" << endl;
    LinkedList<int> L5;
    for(int i = 1; i <= 10; i++) {
        L5.insertFront(i * 10);
    }
    cout << "Built list with 10 elements (100, 90, 80...20, 10): ";
    L5.print();
    cout << "getLength() should be 10: " << L5.getLength() << endl;
    cout << "find(100) should be 0: " << L5.find(100) << endl;
    cout << "find(50) should be 5: " << L5.find(50) << endl;
    cout << "find(10) should be 9: " << L5.find(10) << endl;
    cout << "at(5) should be 50: " << L5.at(5) << endl;
    cout << endl;

    // Test 11: Mixed Operations
    cout << "--- Test 11: Mixed Insert/Delete Operations ---" << endl;
    LinkedList<int> L6;
    L6.insertFront(1);
    L6.insertFront(2);
    L6.insertFront(3);
    cout << "Initial list: ";
    L6.print();

    L6.insertAt(1, 99);
    cout << "After insertAt(1, 99): ";
    L6.print();

    L6.deleteAt(0);
    cout << "After deleteAt(0): ";
    L6.print();

    L6.insertFront(100);
    cout << "After insertFront(100): ";
    L6.print();

    cout << "find(99) should be 1: " << L6.find(99) << endl;
    cout << "at(2) should be 1: " << L6.at(2) << endl;
    cout << endl;

    // Test 12: Edge Cases
    cout << "--- Test 12: Edge Cases ---" << endl;
    LinkedList<int> L7;
    L7.insertFront(42);
    cout << "Single element list: ";
    L7.print();
    cout << "deleteAt(0) should return 42: " << L7.deleteAt(0) << endl;
    cout << "List after delete (empty): ";
    L7.print();
    cout << "Attempting operations on empty list:" << endl;
    cout << "  at(0): " << L7.at(0) << endl;
    cout << "  find(42): " << L7.find(42) << endl;
    cout << "  deleteAt(0): " << L7.deleteAt(0) << endl;
    cout << endl;

    // Test 13: Rule of Three (Copy Ctor, Copy Assignment, Destructor Safety)
    cout << "--- Test 13: Rule of Three ---" << endl;
    LinkedList<int> source;
    source.insertFront(10);
    source.insertFront(20);
    source.insertFront(30);
    cout << "Source list (30, 20, 10): ";
    source.print();

    LinkedList<int> copyConstructed(source);
    cout << "Copy-constructed list: ";
    copyConstructed.print();
    cout << "copyConstructed length should be 3: " << copyConstructed.getLength() << endl;

    source.deleteAt(0);
    source.insertFront(99);
    cout << "Source after modification (99, 20, 10): ";
    source.print();
    cout << "Copy should remain unchanged (30, 20, 10): ";
    copyConstructed.print();
    cout << "copyConstructed.at(0) should be 30: " << copyConstructed.at(0) << endl;

    LinkedList<int> assigned;
    assigned.insertFront(1);
    assigned.insertFront(2);
    cout << "Assigned before copy assignment (2, 1): ";
    assigned.print();
    assigned = source;
    cout << "Assigned after assigned = source (99, 20, 10): ";
    assigned.print();

    assigned.deleteAt(1);
    assigned.insertFront(77);
    cout << "Assigned after modification (77, 99, 10): ";
    assigned.print();
    cout << "Source should remain unchanged (99, 20, 10): ";
    source.print();

    LinkedList<int>& selfRefList = assigned;
    assigned = selfRefList;
    cout << "After self-assignment, assigned should be unchanged: ";
    assigned.print();
    cout << "assigned length should still be 3: " << assigned.getLength() << endl;

    {
        LinkedList<int> scopedCopy(source);
        LinkedList<int> scopedAssigned;
        scopedAssigned = source;
        cout << "Scoped copies created and will be destroyed at end of block." << endl;
    }
    cout << "After scoped destructors, source should still be valid: ";
    source.print();
    cout << endl;

    // Test 14: Sum and Max
    cout << "--- Test 14: Sum and Max ---" << endl;
    LinkedList<int> L8;
    cout << "Empty list sum() should be 0: " << L8.sum() << endl;
    cout << "Empty list max() should be 0: " << L8.max() << endl;
    L8.push_back(15);
    L8.push_back(5);
    L8.push_back(25);
    L8.push_back(10);
    cout << "List should be 15 5 25 10: ";
    L8.print();
    cout << "sum() should be 55: " << L8.sum() << endl;
    cout << "max() should be 25: " << L8.max() << endl;
    cout << endl;

    // Test 15: Iterative Reverse
    cout << "--- Test 15: Iterative Reverse ---" << endl;
    LinkedList<int> L9;
    cout << "Reversing empty list should remain empty: ";
    L9.reverse();
    L9.print();

    L9.push_back(42);
    cout << "Single element before reverse: ";
    L9.print();
    L9.reverse();
    cout << "Single element after reverse should still be 42: ";
    L9.print();

    L9.push_back(84);
    L9.push_back(126);
    L9.push_back(168);
    cout << "Before reverse should be 42 84 126 168: ";
    L9.print();
    L9.reverse();
    cout << "After reverse should be 168 126 84 42: ";
    L9.print();
    cout << "Length should still be 4: " << L9.getLength() << endl;
    cout << endl;

    // Test 16: Recursive Reverse
    cout << "--- Test 16: Recursive Reverse ---" << endl;
    LinkedList<int> L10;
    L10.push_back(1);
    L10.push_back(2);
    L10.push_back(3);
    L10.push_back(4);
    L10.push_back(5);
    cout << "Before reverseRec should be 1 2 3 4 5: ";
    L10.print();
    L10.reverseRec();
    cout << "After reverseRec should be 5 4 3 2 1: ";
    L10.print();
    L10.reverseRec();
    cout << "After reverseRec again should be back to 1 2 3 4 5: ";
    L10.print();
    cout << "Length should still be 5: " << L10.getLength() << endl;
    cout << endl;

    // Test 17: Concat
    cout << "--- Test 17: Concat ---" << endl;
    LinkedList<int> C1;
    C1.push_back(1);
    C1.push_back(2);
    C1.push_back(3);
    LinkedList<int> C2;
    C2.push_back(4);
    C2.push_back(5);
    cout << "C1 before concat should be 1 2 3: ";
    C1.print();
    cout << "C2 should be 4 5: ";
    C2.print();
    C1.concat(C2);
    cout << "C1 after C1.concat(C2) should be 1 2 3 4 5: ";
    C1.print();
    cout << "C1 length should be 5: " << C1.getLength() << endl;
    cout << "C2 should remain unchanged (deep copy append): ";
    C2.print();
    cout << "C2 length should remain 2: " << C2.getLength() << endl;

    LinkedList<int> C3;
    C3.concat(C2);
    cout << "Empty C3 after C3.concat(C2) should be 4 5: ";
    C3.print();
    cout << "C3 length should be 2: " << C3.getLength() << endl;

    LinkedList<int> C4;
    C1.concat(C4);
    cout << "C1 after concat with empty list should stay 1 2 3 4 5: ";
    C1.print();
    cout << "C1 length should still be 5: " << C1.getLength() << endl;

    LinkedList<int> C5;
    C5.push_back(7);
    C5.push_back(8);
    C5.concat(C5);
    cout << "C5 after self concat should be 7 8 7 8: ";
    C5.print();
    cout << "C5 length should be 4: " << C5.getLength() << endl;
    cout << endl;

    cout << "=== ALL TESTS COMPLETE ===" << endl;
}

#include <iostream>
#include "array_list.h"
#include "linked_list.h"
#include "hash_map_chaining.h"
#include "hash_map_OA.h"
#include "stack.h"
#include <string>
#include <stdexcept>
using namespace std;


void ArrayListTest(){
    cout << "=== ARRAY LIST TEST BENCH ===" << endl << endl;

    cout << "--- Test 1: Default Construction ---" << endl;
    ArrayList list;
    cout << "Size should be 0: " << list.Size() << endl;
    cout << "Capacity should be 10: " << list.Capacity() << endl;
    cout << "Display() should show nothing: ";
    list.Display();
    cout << endl;

    cout << "--- Test 2: Append Within Capacity ---" << endl;
    for (int value = 1; value <= 5; value++) {
        list.Append(value * 10);
    }
    cout << "List should be 10 20 30 40 50: ";
    list.Display();
    cout << "Size should be 5: " << list.Size() << endl;
    cout << "Capacity should still be 10: " << list.Capacity() << endl;
    cout << "Get(2) should succeed with 30: ";
    int out = -1;
    if (list.Get(2, out)) cout << out << endl;
    else cout << "failed" << endl;
    cout << endl;

    cout << "--- Test 3: Append Past Capacity ---" << endl;
    for (int value = 6; value <= 12; value++) {
        list.Append(value * 10);
    }
    cout << "List should be 10 through 120 in steps of 10: ";
    list.Display();
    cout << "Size should be 12: " << list.Size() << endl;
    cout << "Capacity should have grown: " << list.Capacity() << endl;
    cout << "LinearSearch(70) should be 6: " << list.LinearSearch(70) << endl;
    cout << "LinearSearch(999) should be -1: " << list.LinearSearch(999) << endl;
    cout << endl;

    cout << "--- Test 4: Insert Valid Positions ---" << endl;
    ArrayList insertList(4);
    cout << "Insert into empty list at index 0: " << insertList.Insert(0, 100) << endl;
    cout << "Insert at end (index == size): " << insertList.Insert(1, 200) << endl;
    cout << "Insert in middle: " << insertList.Insert(1, 150) << endl;
    cout << "Current list should be 100 150 200: ";
    insertList.Display();
    cout << "Size should be 3: " << insertList.Size() << endl;
    cout << endl;

    cout << "--- Test 5: Insert Invalid Positions ---" << endl;
    cout << "Insert at negative index should fail: " << insertList.Insert(-1, 5) << endl;
    cout << "Insert past end should fail: " << insertList.Insert(10, 5) << endl;
    cout << endl;

    cout << "--- Test 6: Delete Operations ---" << endl;
    insertList.Delete(1);
    cout << "After Delete(1), list should be 100 200: ";
    insertList.Display();
    insertList.Delete(0);
    cout << "After Delete(0), list should be 200: ";
    insertList.Display();
    insertList.Delete(0);
    cout << "After Delete(0), list should be empty: ";
    insertList.Display();
    cout << endl;

    cout << "--- Test 7: Bounds Safety ---" << endl;
    cout << "Get(0) on empty list should fail: ";
    if (insertList.Get(0, out)) cout << out << endl;
    else cout << "failed" << endl;
    cout << "Get(-1) should fail: ";
    if (insertList.Get(-1, out)) cout << out << endl;
    else cout << "failed" << endl;
    cout << endl;

    cout << "--- Test 8: Negative Capacity Rejection ---" << endl;
    try {
        ArrayList bad(-3);
        cout << "Constructed bad list unexpectedly" << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Negative capacity rejected as expected: " << e.what() << endl;
    }
    cout << endl;

    cout << "--- Test 9: Copy Constructor Deep Copy ---" << endl;
    ArrayList original;
    original.Append(11);
    original.Append(22);
    original.Append(33);
    ArrayList copied(original);
    cout << "Original should be 11 22 33: ";
    original.Display();
    cout << "Copied should be 11 22 33: ";
    copied.Display();
    original.Delete(0); // mutate source after copy
    original.Append(44);
    cout << "Original after mutation should be 22 33 44: ";
    original.Display();
    cout << "Copied should remain 11 22 33: ";
    copied.Display();
    cout << "Copied size should be 3: " << copied.Size() << endl;
    cout << endl;

    cout << "--- Test 10: Copy Assignment Deep Copy + Self-Assignment ---" << endl;
    ArrayList assigned;
    assigned.Append(1);
    assigned.Append(2);
    cout << "Assigned before copy (should be 1 2): ";
    assigned.Display();
    assigned = original;
    cout << "Assigned after assigned = original (should be 22 33 44): ";
    assigned.Display();
    assigned.Delete(1);
    assigned.Append(55);
    cout << "Assigned after mutation should be 22 44 55: ";
    assigned.Display();
    cout << "Original should remain 22 33 44: ";
    original.Display();
    ArrayList& selfRefArray = assigned;
    assigned = selfRefArray;
    cout << "Assigned after self-assignment should be unchanged: ";
    assigned.Display();
    cout << "Assigned size should still be 3: " << assigned.Size() << endl;
    cout << endl;

    cout << "--- Test 11: Binary Search (Recursive + Iterative) ---" << endl;
    ArrayList sorted;
    for (int value = 10; value <= 100; value += 10) {
        sorted.Append(value);
    }
    cout << "Sorted list should be 10 20 30 40 50 60 70 80 90 100: ";
    sorted.Display();
    cout << "binarySearch(10, true) should be 0: " << sorted.binarySearch(10, true) << endl;
    cout << "binarySearch(70, true) should be 6: " << sorted.binarySearch(70, true) << endl;
    cout << "binarySearch(100, true) should be 9: " << sorted.binarySearch(100, true) << endl;
    cout << "binarySearch(55, true) should be -1: " << sorted.binarySearch(55, true) << endl;
    cout << "binarySearch(10, false) should be 0: " << sorted.binarySearch(10, false) << endl;
    cout << "binarySearch(70, false) should be 6: " << sorted.binarySearch(70, false) << endl;
    cout << "binarySearch(100, false) should be 9: " << sorted.binarySearch(100, false) << endl;
    cout << "binarySearch(55, false) should be -1: " << sorted.binarySearch(55, false) << endl;

    ArrayList emptySorted;
    cout << "binarySearch on empty list should be -1: "
         << emptySorted.binarySearch(10, true) << ", "
         << emptySorted.binarySearch(10, false) << endl;
    cout << endl;

    cout << "=== ARRAY LIST TEST COMPLETE ===" << endl;
}

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

void HashMapChainingTest(){
    cout << "=== HASH MAP CHAINING TEST BENCH ===" << endl << endl;

    HashMapChaining<string> table;
    string out;

    cout << "--- Test 1: Initial State ---" << endl;
    cout << "Initial load factor should be 0: " << table.getLoadFactor() << endl;
    cout << "Initial size should be 0: " << table.getSize() << endl;
    cout << "Initial capacity should be 23: " << table.getCapacity() << endl;
    cout << endl;

    cout << "--- Test 2: Basic Insertions ---" << endl;
    cout << "insert(1, one) should be 1: " << table.insert(1, "one") << endl;
    cout << "insert(2, two) should be 1: " << table.insert(2, "two") << endl;
    cout << "insert(3, three) should be 1: " << table.insert(3, "three") << endl;
    cout << "Load factor should be about 3/23 ~= 0.1304: " << table.getLoadFactor() << endl;
    cout << "Size should be 3: " << table.getSize() << endl;
    cout << endl;

    cout << "--- Test 3: Duplicate Key Rejection ---" << endl;
    cout << "insert(2, TWO) should be 0: " << table.insert(2, "TWO") << endl;
    cout << "Load factor should be unchanged: " << table.getLoadFactor() << endl;
    cout << endl;

    cout << "--- Test 4: Collision Handling (Chaining) ---" << endl;
    // With capacity 23, these map to the same bucket: 1, 24, 47.
    cout << "insert(24, twenty-four) should be 1: " << table.insert(24, "twenty-four") << endl;
    cout << "insert(47, forty-seven) should be 1: " << table.insert(47, "forty-seven") << endl;
    cout << "Table after collision inserts:" << endl;
    table.print();
    cout << endl;

    cout << "--- Test 5: Rehash Trigger ---" << endl;
    int successfulInserts = 0;
    for (int key = 100; key < 125; key++) {
        if (table.insert(key, "value_" + to_string(key))) {
            successfulInserts++;
        }
    }
    cout << "Successful inserts from [100..124]: " << successfulInserts << endl;
    cout << "Load factor after bulk insert (should stay <= 0.75 if rehash works): "
         << table.getLoadFactor() << endl;
        cout << "Capacity after possible rehash should be >= 23: " << table.getCapacity() << endl;

    cout << endl;
    cout << "--- Test 6: Get Existing Keys ---" << endl;
        if (table.get(1, out)) cout << "get(1) should be one: " << out << endl;
        else cout << "get(1) failed unexpectedly" << endl;
        if (table.get(24, out)) cout << "get(24) should be twenty-four: " << out << endl;
        else cout << "get(24) failed unexpectedly" << endl;
        if (table.get(124, out)) cout << "get(124) should be value_124: " << out << endl;
        else cout << "get(124) failed unexpectedly" << endl;

    cout << endl;
    cout << "--- Test 7: Get Missing Key ---" << endl;
        bool foundMissing = table.get(9999, out);
        cout << "get(9999) should return false: " << foundMissing << endl;

    cout << endl;
    cout << "--- Test 8: Remove Existing Key ---" << endl;
    double beforeRemove = table.getLoadFactor();
        int sizeBeforeRemove = table.getSize();
    table.remove(24);
        bool removedCheck = table.get(24, out);
    double afterRemove = table.getLoadFactor();
        cout << "After remove(24), get(24) should return false: " << removedCheck << endl;
    cout << "Load factor should decrease:" << endl;
    cout << "  before: " << beforeRemove << endl;
    cout << "  after : " << afterRemove << endl;
        cout << "Size should decrease by 1: " << sizeBeforeRemove << " -> " << table.getSize() << endl;

    cout << endl;
    cout << "--- Test 9: Remove Missing Key ---" << endl;
    double beforeMissingRemove = table.getLoadFactor();
    table.remove(987654);
    double afterMissingRemove = table.getLoadFactor();
    cout << "Load factor should be unchanged after removing missing key:" << endl;
    cout << "  before: " << beforeMissingRemove << endl;
    cout << "  after : " << afterMissingRemove << endl;

    cout << endl;
        cout << "--- Test 10: Clear / Size / Capacity ---" << endl;
        int capBeforeClear = table.getCapacity();
        table.clear();
        cout << "After clear, size should be 0: " << table.getSize() << endl;
        cout << "After clear, load factor should be 0: " << table.getLoadFactor() << endl;
        cout << "Capacity should remain unchanged after clear: "
            << capBeforeClear << " -> " << table.getCapacity() << endl;

        cout << endl;
    cout << "Final table snapshot:" << endl;
    table.print();
    cout << endl;

    cout << "=== HASH MAP CHAINING TESTS COMPLETE ===" << endl;
}

void HashMapOATest(){
    auto runOATests = [](bool useQuadratic){
       cout << "=== HASH MAP OPEN ADDRESSING TEST BENCH ("
           << (useQuadratic ? "QUADRATIC" : "LINEAR")
           << " PROBING) ===" << endl << endl;

       HashMapOA<string> table(useQuadratic);
       string out;

       cout << "--- Test 1: Initial State ---" << endl;
       cout << "Initial load factor should be 0: " << table.getLoadFactor() << endl;
       cout << "Initial size should be 0: " << table.getSize() << endl;
       cout << "Initial capacity should be 23: " << table.getCapacity() << endl;
       cout << endl;

       cout << "--- Test 2: Basic Insertions ---" << endl;
       cout << "insert(1, one) should be 1: " << table.insert(1, "one") << endl;
       cout << "insert(2, two) should be 1: " << table.insert(2, "two") << endl;
       cout << "insert(3, three) should be 1: " << table.insert(3, "three") << endl;
       cout << "Load factor should be about 3/23 ~= 0.1304: " << table.getLoadFactor() << endl;
       cout << "Size should be 3: " << table.getSize() << endl;
       cout << endl;

       cout << "--- Test 3: Duplicate Key Rejection ---" << endl;
       cout << "insert(2, TWO) should be 0: " << table.insert(2, "TWO") << endl;
       cout << "Size should remain 3: " << table.getSize() << endl;
       cout << endl;

       cout << "--- Test 4: Collision Handling ---" << endl;
       // With capacity 23, these collide with key 1: 24, 47.
       cout << "insert(24, twenty-four) should be 1: " << table.insert(24, "twenty-four") << endl;
       cout << "insert(47, forty-seven) should be 1: " << table.insert(47, "forty-seven") << endl;
       cout << "Current table snapshot:" << endl;
       table.print();
       cout << endl;

       cout << "--- Test 5: Get Existing and Missing Keys ---" << endl;
       if (table.get(1, out)) cout << "get(1) should be one: " << out << endl;
       else cout << "get(1) failed unexpectedly" << endl;
       if (table.get(24, out)) cout << "get(24) should be twenty-four: " << out << endl;
       else cout << "get(24) failed unexpectedly" << endl;
       if (table.get(9999, out)) cout << "get(9999) should fail but returned: " << out << endl;
       else cout << "get(9999) should be false: 0" << endl;
       cout << endl;

       cout << "--- Test 6: Tombstone Reuse After Remove ---" << endl;
       int sizeBeforeRemove = table.getSize();
       cout << "remove(24) should be 1: " << table.remove(24) << endl;
       cout << "Size should decrease by 1: " << sizeBeforeRemove << " -> " << table.getSize() << endl;
       if (table.get(24, out)) cout << "get(24) should be false but returned: " << out << endl;
       else cout << "get(24) should now be false: 0" << endl;
       cout << "insert(70, seventy) should be 1 (may reuse deleted slot): " << table.insert(70, "seventy") << endl;
       if (table.get(70, out)) cout << "get(70) should be seventy: " << out << endl;
       else cout << "get(70) failed unexpectedly" << endl;
       cout << endl;

       cout << "--- Test 7: Negative Keys ---" << endl;
       cout << "insert(-5, neg-five) should be 1: " << table.insert(-5, "neg-five") << endl;
       if (table.get(-5, out)) cout << "get(-5) should be neg-five: " << out << endl;
       else cout << "get(-5) failed unexpectedly" << endl;
       cout << endl;

       cout << "--- Test 8: Rehash Trigger and Integrity ---" << endl;
       int capBefore = table.getCapacity();
       int successfulInserts = 0;
       for (int key = 100; key < 140; key++) {
          if (table.insert(key, "value_" + to_string(key))) {
             successfulInserts++;
          }
       }
       cout << "Successful inserts from [100..139]: " << successfulInserts << endl;
       cout << "Capacity should stay same or grow after rehash: "
           << capBefore << " -> " << table.getCapacity() << endl;
       if (table.get(1, out)) cout << "get(1) after rehash should still be one: " << out << endl;
       else cout << "get(1) failed after rehash" << endl;
       if (table.get(139, out)) cout << "get(139) should be value_139: " << out << endl;
       else cout << "get(139) failed unexpectedly" << endl;
       cout << endl;

       cout << "--- Test 9: Remove Missing Key ---" << endl;
       int sizeBeforeMissingRemove = table.getSize();
       cout << "remove(999999) should be 0: " << table.remove(999999) << endl;
       cout << "Size should remain unchanged: "
           << sizeBeforeMissingRemove << " -> " << table.getSize() << endl;
       cout << endl;

       cout << "--- Test 10: Clear / Reset State ---" << endl;
       int capBeforeClear = table.getCapacity();
       table.clear();
       cout << "After clear, size should be 0: " << table.getSize() << endl;
       cout << "After clear, load factor should be 0: " << table.getLoadFactor() << endl;
       cout << "Capacity should remain unchanged after clear: "
           << capBeforeClear << " -> " << table.getCapacity() << endl;
       if (table.get(1, out)) cout << "get(1) after clear should fail but returned: " << out << endl;
       else cout << "get(1) after clear should be false: 0" << endl;
       cout << endl;

       cout << "--- Test 11: Insert After Clear ---" << endl;
       cout << "insert(7, seven) should be 1: " << table.insert(7, "seven") << endl;
       if (table.get(7, out)) cout << "get(7) should be seven: " << out << endl;
       else cout << "get(7) failed unexpectedly" << endl;
       cout << "Final table snapshot:" << endl;
       table.print();
       cout << endl;

       cout << "=== HASH MAP OPEN ADDRESSING TESTS COMPLETE ("
           << (useQuadratic ? "QUADRATIC" : "LINEAR")
           << ") ===" << endl << endl;
    };

    runOATests(false);//linear
    runOATests(true);//quadratic
}

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

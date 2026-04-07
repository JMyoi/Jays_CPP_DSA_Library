#include <iostream>
#include "linked_list.h"
#include "hash_map_chaining.h"
#include "hash_map_OA.h"
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

    assigned = assigned;
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
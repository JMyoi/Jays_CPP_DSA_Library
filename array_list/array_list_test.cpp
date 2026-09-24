#include <iostream>
#include <string>
#include <stdexcept>
#include "test_bench.h"
#include "array_list.h"
using namespace std;

void ArrayListTest(){
    cout << "=== ARRAY LIST TEST BENCH ===" << endl << endl;

    cout << "--- Test 1: Default Construction ---" << endl;
    ArrayList<int> list;
    cout << "Size should be 0: " << list.getSize() << endl;
    cout << "Capacity should be 5: " << list.getCapacity() << endl;
    cout << "display() should show nothing: ";
    list.display();
    cout << endl;

    cout << "--- Test 2: Append Within Capacity ---" << endl;
    for (int value = 1; value <= 5; value++) {
        list.append(value * 10);
    }
    cout << "List should be 10 20 30 40 50: ";
    list.display();
    cout << "Size should be 5: " << list.getSize() << endl;
    cout << "Capacity should still be 5: " << list.getCapacity() << endl;
    cout << "get(2) should succeed with 30: ";
    int out = -1;
    if (list.get(2, out)) cout << out << endl;
    else cout << "failed" << endl;
    cout << endl;

    cout << "--- Test 3: Append Past Capacity ---" << endl;
    for (int value = 6; value <= 12; value++) {
        list.append(value * 10);
    }
    cout << "List should be 10 through 120 in steps of 10: ";
    list.display();
    cout << "Size should be 12: " << list.getSize() << endl;
    cout << "Capacity should have grown: " << list.getCapacity() << endl;
    cout << "linearSearch(70) should be 6: " << list.linearSearch(70) << endl;
    cout << "linearSearch(999) should be -1: " << list.linearSearch(999) << endl;
    cout << endl;

    cout << "--- Test 4: Insert Valid Positions ---" << endl;
    ArrayList<int> insertList(4);
    cout << "Insert into empty list at index 0: " << insertList.insert(0, 100) << endl;
    cout << "Insert at end (index == size): " << insertList.insert(1, 200) << endl;
    cout << "Insert in middle: " << insertList.insert(1, 150) << endl;
    cout << "Current list should be 100 150 200: ";
    insertList.display();
    cout << "Size should be 3: " << insertList.getSize() << endl;
    cout << endl;

    cout << "--- Test 5: Insert Invalid Positions ---" << endl;
    cout << "Insert at negative index should fail: " << insertList.insert(-1, 5) << endl;
    cout << "Insert past end should fail: " << insertList.insert(10, 5) << endl;
    cout << endl;

    cout << "--- Test 6: Delete Operations ---" << endl;
    insertList.deleteAt(1);
    cout << "After deleteAt(1), list should be 100 200: ";
    insertList.display();
    insertList.deleteAt(0);
    cout << "After deleteAt(0), list should be 200: ";
    insertList.display();
    insertList.deleteAt(0);
    cout << "After deleteAt(0), list should be empty: ";
    insertList.display();
    cout << endl;

    cout << "--- Test 7: Bounds Safety ---" << endl;
    cout << "get(0) on empty list should fail: ";
    if (insertList.get(0, out)) cout << out << endl;
    else cout << "failed" << endl;
    cout << "get(-1) should fail: ";
    if (insertList.get(-1, out)) cout << out << endl;
    else cout << "failed" << endl;
    cout << endl;

    cout << "--- Test 8: Negative Capacity Rejection ---" << endl;
    try {
        ArrayList<int> bad(-3);
        cout << "Constructed bad list unexpectedly" << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Negative capacity rejected as expected: " << e.what() << endl;
    }
    cout << endl;

    cout << "--- Test 9: Copy Constructor Deep Copy ---" << endl;
    ArrayList<int> original;
    original.append(11);
    original.append(22);
    original.append(33);
    ArrayList<int> copied(original);
    cout << "Original should be 11 22 33: ";
    original.display();
    cout << "Copied should be 11 22 33: ";
    copied.display();
    original.deleteAt(0); // mutate source after copy
    original.append(44);
    cout << "Original after mutation should be 22 33 44: ";
    original.display();
    cout << "Copied should remain 11 22 33: ";
    copied.display();
    cout << "Copied size should be 3: " << copied.getSize() << endl;
    cout << endl;

    cout << "--- Test 10: Copy Assignment Deep Copy + Self-Assignment ---" << endl;
    ArrayList<int> assigned;
    assigned.append(1);
    assigned.append(2);
    cout << "Assigned before copy (should be 1 2): ";
    assigned.display();
    assigned = original;
    cout << "Assigned after assigned = original (should be 22 33 44): ";
    assigned.display();
    assigned.deleteAt(1);
    assigned.append(55);
    cout << "Assigned after mutation should be 22 44 55: ";
    assigned.display();
    cout << "Original should remain 22 33 44: ";
    original.display();
    ArrayList<int>& selfRefArray = assigned;
    assigned = selfRefArray;
    cout << "Assigned after self-assignment should be unchanged: ";
    assigned.display();
    cout << "Assigned size should still be 3: " << assigned.getSize() << endl;
    cout << endl;

    cout << "--- Test 11: Binary Search (Recursive + Iterative) ---" << endl;
    ArrayList<int> sorted;
    for (int value = 10; value <= 100; value += 10) {
        sorted.append(value);
    }
    cout << "Sorted list should be 10 20 30 40 50 60 70 80 90 100: ";
    sorted.display();
    cout << "binarySearch(10, true) should be 0: " << sorted.binarySearch(10, true) << endl;
    cout << "binarySearch(70, true) should be 6: " << sorted.binarySearch(70, true) << endl;
    cout << "binarySearch(100, true) should be 9: " << sorted.binarySearch(100, true) << endl;
    cout << "binarySearch(55, true) should be -1: " << sorted.binarySearch(55, true) << endl;
    cout << "binarySearch(10, false) should be 0: " << sorted.binarySearch(10, false) << endl;
    cout << "binarySearch(70, false) should be 6: " << sorted.binarySearch(70, false) << endl;
    cout << "binarySearch(100, false) should be 9: " << sorted.binarySearch(100, false) << endl;
    cout << "binarySearch(55, false) should be -1: " << sorted.binarySearch(55, false) << endl;

    ArrayList<int> emptySorted;
    cout << "binarySearch on empty list should be -1: "
         << emptySorted.binarySearch(10, true) << ", "
         << emptySorted.binarySearch(10, false) << endl;
    cout << endl;

    cout << "--- Test 12: Remove By Value ---" << endl;
    ArrayList<int> removeList;
    removeList.append(5);
    removeList.append(7);
    removeList.append(5);
    removeList.append(9);
    removeList.append(3);
    cout << "Starting list should be 5 7 5 9 3: ";
    removeList.display();
    cout << "remove(5) should succeed (1): " << removeList.remove(5) << endl;
    cout << "Only first 5 removed, list should be 7 5 9 3: ";
    removeList.display();
    cout << "remove(3) at tail should succeed (1): " << removeList.remove(3) << endl;
    cout << "List should be 7 5 9: ";
    removeList.display();
    cout << "remove(7) at head should succeed (1): " << removeList.remove(7) << endl;
    cout << "List should be 5 9: ";
    removeList.display();
    cout << "remove(42) not in list should fail (0): " << removeList.remove(42) << endl;
    cout << "List should be unchanged 5 9: ";
    removeList.display();
    cout << "Size should be 2: " << removeList.getSize() << endl;
    removeList.remove(5);
    removeList.remove(9);
    cout << "After removing all, list should be empty: ";
    removeList.display();
    cout << "Size should be 0: " << removeList.getSize() << endl;
    cout << "remove(5) on empty list should fail (0): " << removeList.remove(5) << endl;
    cout << endl;

    cout << "--- Test 13: Comparison Operators == and != ---" << endl;
    ArrayList<int> cmpA(3);
    ArrayList<int> cmpB(20);
    for (int value = 1; value <= 3; value++) {
        cmpA.append(value);
        cmpB.append(value);
    }
    cout << "cmpA should be 1 2 3: ";
    cmpA.display();
    cout << "cmpB should be 1 2 3: ";
    cmpB.display();
    cout << "Same elements, different capacity: cmpA == cmpB should be 1: " << (cmpA == cmpB) << endl;
    cout << "cmpA != cmpB should be 0: " << (cmpA != cmpB) << endl;

    ArrayList<int> cmpShort;
    cmpShort.append(1);
    cmpShort.append(2);
    cout << "Different sizes (1 2 3 vs 1 2): cmpA == cmpShort should be 0: " << (cmpA == cmpShort) << endl;
    cout << "cmpA != cmpShort should be 1: " << (cmpA != cmpShort) << endl;

    ArrayList<int> cmpDiff;
    cmpDiff.append(1);
    cmpDiff.append(9);
    cmpDiff.append(3);
    cout << "Same size, one element differs (1 2 3 vs 1 9 3): cmpA == cmpDiff should be 0: " << (cmpA == cmpDiff) << endl;
    cout << "cmpA != cmpDiff should be 1: " << (cmpA != cmpDiff) << endl;

    ArrayList<int> cmpReordered;
    cmpReordered.append(3);
    cmpReordered.append(2);
    cmpReordered.append(1);
    cout << "Same elements, different order (1 2 3 vs 3 2 1): cmpA == cmpReordered should be 0: " << (cmpA == cmpReordered) << endl;

    ArrayList<int> emptyA;
    ArrayList<int> emptyB(50);
    cout << "Two empty lists: emptyA == emptyB should be 1: " << (emptyA == emptyB) << endl;
    cout << "emptyA != emptyB should be 0: " << (emptyA != emptyB) << endl;
    cout << "Empty vs non-empty: emptyA == cmpA should be 0: " << (emptyA == cmpA) << endl;

    cout << "Self comparison: cmpA == cmpA should be 1: " << (cmpA == cmpA) << endl;
    cout << "cmpA != cmpA should be 0: " << (cmpA != cmpA) << endl;

    ArrayList<int> cmpCopy(cmpA);
    cout << "Copy-constructed list: cmpCopy == cmpA should be 1: " << (cmpCopy == cmpA) << endl;
    cmpCopy.append(4);
    cout << "After cmpCopy.append(4): cmpCopy == cmpA should be 0: " << (cmpCopy == cmpA) << endl;
    cmpCopy.remove(4);
    cout << "After cmpCopy.remove(4): cmpCopy == cmpA should be 1 again: " << (cmpCopy == cmpA) << endl;

    const ArrayList<int>& constRefA = cmpA;
    const ArrayList<int>& constRefB = cmpB;
    cout << "Through const references: constRefA == constRefB should be 1: " << (constRefA == constRefB) << endl;
    cout << endl;

    cout << "--- Test 14: Template With std::string ---" << endl;
    ArrayList<string> words(2);
    words.append("apple");
    words.append("banana");
    words.append("cherry"); // forces a resize past capacity 2
    words.insert(1, "avocado");
    cout << "List should be apple avocado banana cherry: ";
    words.display();
    cout << "Size should be 4: " << words.getSize() << endl;
    string word;
    cout << "get(3) should be cherry: ";
    if (words.get(3, word)) cout << word << endl;
    else cout << "failed" << endl;
    cout << "linearSearch(\"banana\") should be 2: " << words.linearSearch("banana") << endl;
    cout << "binarySearch(\"cherry\", true) should be 3: " << words.binarySearch("cherry", true) << endl;
    cout << "binarySearch(\"blueberry\", false) should be -1: " << words.binarySearch("blueberry", false) << endl;
    cout << "remove(\"banana\") should succeed (1): " << words.remove("banana") << endl;
    cout << "List should be apple avocado cherry: ";
    words.display();
    ArrayList<string> wordsCopy(words);
    cout << "Copy == original should be 1: " << (wordsCopy == words) << endl;
    wordsCopy.deleteAt(0);
    cout << "After deleteAt(0) on copy, copy != original should be 1: " << (wordsCopy != words) << endl;
    cout << "Original should remain apple avocado cherry: ";
    words.display();
    cout << endl;

    cout << "=== ARRAY LIST TEST COMPLETE ===" << endl;
}

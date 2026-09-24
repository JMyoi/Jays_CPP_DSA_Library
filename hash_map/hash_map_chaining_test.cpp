#include <iostream>
#include <string>
#include <stdexcept>
#include "test_bench.h"
#include "hash_map_chaining.h"
using namespace std;

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

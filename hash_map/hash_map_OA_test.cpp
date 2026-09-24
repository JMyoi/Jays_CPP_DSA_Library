#include <iostream>
#include <string>
#include <stdexcept>
#include "test_bench.h"
#include "hash_map_OA.h"
using namespace std;

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

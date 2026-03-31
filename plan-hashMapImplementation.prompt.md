# Hash Map Implementation Plan

Design two hash map classes following your library's conventions: Hash_Map_Chaining (collision resolution via chaining) and Hash_Map_OA (open addressing with linear/quadratic probing). Both will use `int` keys, implement the Rule of Three, follow your naming patterns, and trigger rehashing when load factor exceeds 0.75.

## Hash_Map_Chaining Structure

### Data Members:
1. `_table` — array of linked lists (each bucket is a chain)
2. `_capacity` — current table size
3. `_size` — number of key-value pairs stored
4. `_loadFactor` — tracks when to rehash

### Core Methods:
1. `insert(int key, int value)` — adds/updates key-value pair
2. `get(int key)` — returns value or `-1` if not found
3. `remove(int key)` — deletes key-value pair
4. `contains(int key)` — checks if key exists
5. `clear()` — removes all entries
6. `getSize()` — returns current number of pairs
7. `getCapacity()` — returns table size

### Private Helper Methods:
1. `_hashFunction(int key)` — modular hashing
2. `_rehash()` — expands table and reinserts when load factor > 0.75
3. `_findNode(int key)` — finds node in specific bucket chain

### Additional Considerations:
1. Define a simple `Node` struct (key, value, next pointer) for the linked list in each bucket
2. When rehashing, what should the new capacity be? (e.g., double, multiply by 1.5, next prime)
3. Error handling: return `-1` for failed `get()`, or print messages like your other structures?

---

## Hash_Map_OA Structure

### Data Members:
1. `_table` — array of key-value pairs (with tombstone marker for deleted entries)
2. `_capacity` — current table size
3. `_size` — number of active key-value pairs
4. `_deleted` — count of tombstones (for occupancy calculations)
5. `_probeType` — 0 for linear, 1 for quadratic (or enum for clarity)

### Core Methods:
1. `insert(int key, int value)` — adds/updates using probing
2. `get(int key)` — finds value using probing
3. `remove(int key)` — marks as deleted (tombstone)
4. `contains(int key)` — checks if key exists
5. `clear()` — resets table
6. `getSize()` — returns active pairs count
7. `getCapacity()` — returns table size

### Private Helper Methods:
1. `_hashFunction(int key)` — initial hash
2. `_linearProbe(int key, bool forInsert)` — finds slot using linear probing
3. `_quadraticProbe(int key, bool forInsert)` — finds slot using quadratic probing
4. `_probe(int key, bool forInsert)` — dispatcher based on `_probeType`
5. `_rehash()` — expands and recalculates all positions (skip tombstones)

### Additional Considerations:
1. Define a status field for each entry: EMPTY, OCCUPIED, DELETED (tombstone)
2. Constructor: `Hash_Map_OA(int probeType = 0)` to toggle linear (0) vs quadratic (1)
3. Quadratic probing formula: `(hash + i²) % capacity` — what should `i` increment by?
4. Load factor calculation: should it count tombstones as occupancy? (typically yes)
5. When rehashing, tombstones should be eliminated (don't reinsert deleted entries)

---

## Further Considerations

1. **Initial Capacity** — What size should both maps start with? (e.g., 16, 11 for prime hashing?)
2. **Rehashing Threshold** — Stick with load factor > 0.75, or have separate thresholds for chaining vs OA?
3. **Rule of Three** — Match your existing pattern: custom destructor, copy constructor, copy assignment operator?
4. **Testing** — Should you test both implementations side-by-side with identical key-value operations to verify correctness?
5. **Collision Statistics** — Worth tracking collisions for analysis (optional, but educational)?

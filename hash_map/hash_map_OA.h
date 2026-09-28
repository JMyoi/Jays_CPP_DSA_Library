/*
Implementing hash map to store key value pairs, unique keys
    Keys are only of int type, for simplicity of hash function.
    values can be of any type, template
handle collision via open addressing: Linear probing
rehash when load factor > 0.7

*/

#pragma once
#include <vector>
using namespace std;


/*
//For open addressing we need to keep track of the state of each Data entry, 
//so You know when to stop probing for get() 
//stop at an empty slot, not at a tombstone. Tombstones mean "something was deleted here, keep going."
empty: no values yet, null
occupied: value currently here
deleted: value was here but removed

*/
enum class Status {empty, occupied, deleted};

template <typename T>
struct KVPair{
    int key;
    T value;
    Status status = Status::empty;
};

template <typename T>
class HashMapOA{
public:
    HashMapOA();

    bool insert(int key, const T& vlaue); // fails if tyrying to insert duplicate key
    bool get(int key, T& value) const;
    bool remove(int key);// returns false if key was not found

    void print() const;
    void clear();
    double getLoadFactor() const;
    int getSize() const {return size;}
    int getCapacity() const {return capacity;}

private:
    vector<KVPair<T>> HashTable;
    int size; // number of elements inserted
    int capacity; // number of buckets, size of hash table

    int computeHash(int key) const;
    void rehash();
};

#include "hash_map_OA.tpp"


/*
problem: 

When lookups actually slow down
A search only stops at an empty slot.

get for a key that isn't in the table walks past occupied slots and tombstones until it reaches an empty slot.
insert does the same thing, even when it's going to reuse a tombstone, because it has to confirm the key isn't a duplicate further along.
So the cost of an operation depends on how far it is to the nearest empty slot. Tombstones don't count as empty.

Deleting the same keys you inserted is mostly okay. Your insert reuses the first tombstone it finds, so reinserting the same keys lands them back in their old slots.

The real problem is churn with different keys. For example, you insert keys 1–16, delete them, insert 30–45, delete them, and so on. Each new batch lands partly in slots that were still empty. Over time every slot becomes either occupied or deleted, and none are empty. Meanwhile:

size stays small, so the load factor looks tiny and rehash() never runs.
Every lookup for a missing key and every insert probes all capacity slots.
It's slightly worse than O(n). The cost is O(capacity), which has no relation to how many items you're actually storing. You could have 1 item in a 1,000-slot table and still pay 1,000 probes per miss.

Fix 1: Count tombstones toward the rehash decision (the usual fix)
Track a second counter, deletedCount:
remove: size-- and deletedCount++
insert into a tombstone: size++ and deletedCount--
insert into an empty slot: size++ only
Base the rehash on how many slots are used: trigger it when (size + deletedCount) / capacity > 0.7. That fraction measures how few empty slots are left, which is what actually determines probe length.
Rehash already clears tombstones. It copies only occupied entries into a fresh table, so every tombstone disappears and deletedCount goes back to 0.
The rehash has to decide on a size. If you always double, heavy churn keeps growing the table even though you store only a few items. The standard approach is to:

double the capacity if the table is mostly live items (size is high), or
rebuild at the same capacity if it's mostly tombstones, just to clean them out.
Cost: each rehash is O(capacity), but it can only happen after about 0.7 × capacity inserts. Spread over those operations, that's still O(1) per operation on average.
*/
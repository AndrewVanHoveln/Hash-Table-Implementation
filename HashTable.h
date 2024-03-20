#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <functional>

using namespace std;

template <typename T, typename U>
class HashTable {

    struct Entry {
        T key;
        U value;
    };

    public:
        HashTable();
        ~HashTable();
        U& operator[](const T& key);
        void printTable();
        void insert(const T& key, const U& value);

        
    private:
        vector<vector<Entry*>> table;
        size_t size;
        size_t capacity;
        size_t index;
        size_t max_2d;

        const vector<size_t> tableSizes = {
            31, 61, 127, 251, 509, 1021, 2053, 4093, 8191, 16381, 
            32749, 65521, 131071, 262139, 524287, 1048573, 2097143, 4194301, 8388593, 16777213
        };

        size_t hash(const T& key) const {
            return static_cast<size_t>(key) % capacity;
        }

        void rehash();

        void insert(Entry* e);
    
};

#include "HashTable.cpp"

#endif
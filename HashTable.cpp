/*
*   Created by Andrew Van Hoveln
*/

//Implementation of hash table methods

#include "HashTable.h"
#include <vector>

using namespace std;


template <typename T, typename U>
HashTable<T, U>::HashTable(){
    this->size = 0;
    this->index = 0;
    this->capacity = this->tableSizes[this->index];
    this->table = vector<vector<Entry*>>(capacity);
    this->max_2d = capacity / 8;
}

template <typename T, typename U>
HashTable<T, U>::~HashTable(){
    for(int i = 0; i < table.size(); i++){
        if (table[i].size() < 0)
            continue;
        
        for (int j = 0; j < table[i].size(); j++){
            delete table[i][j];
        }
    }
}

template <typename T, typename U>
U& HashTable<T, U>::operator[](const T& key){
    size_t i = hash(key);

    for(int j = 0; j < table[i].size(); j++){
        if (table[i][j]->key == key){
            return table[i][j]->value;
        }
    }

    Entry* e = new Entry();
    e->key = key;
    table[i].push_back(e);
    size++;

    if(table[i].size() >= max_2d){
        // cout<<"REHASHING "<<key<<" "<<endl;
        rehash();
    }
    
    return e->value;
}

template <typename T, typename U>
void HashTable<T, U>::insert(const T& key, const U& value){
    size_t i = hash(key);
    for(int j = 0; j < table[i].size(); j++){
        if (table[i][j]->key == key){
            table[i][j]->value = value;
            return;
        }
    }   
    
    Entry* e = new Entry();
    e->key = key;
    e->value = value;
    table[i].push_back(e);
    size++;

    if(table[i].size() >= max_2d){
        // cout<<"REHASHING "<<key<<" "<<value<<endl;
        rehash();
    }
}

template <typename T, typename U>
void HashTable<T, U>::printTable(){
    for (int i = 0; i < table.size(); i++){
        for (int j = 0; j < table[i].size(); j++){
            cout<<"("<<table[i][j]->key<<", "<<table[i][j]->value<<") ";
        }
        if (table[i].size() > 0){
            cout<<"\n";
        }
    }
}

template <typename T, typename U>
void HashTable<T, U>::rehash(){
    if(index + 1 > tableSizes.size())
        return;
    
    index++;
    capacity = tableSizes[index];
    max_2d = capacity / 8;

    vector<vector<Entry*>> oldTable(capacity);
    table.swap(oldTable);

    for(int i = 0; i < oldTable.size(); i++){
        for(int j = 0; j < oldTable[i].size(); j++){
            insert(oldTable[i][j]);
        }
    }
}

template <typename T, typename U>
void HashTable<T, U>::insert(Entry* e){
    size_t i = hash(e->key);
    table[i].push_back(e);
}

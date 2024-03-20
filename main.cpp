/*
*   Created by Andrew Van Hoveln
*/

// Main file used to test the hash table

#include <iostream>
#include "HashTable.h"
#include <random>

using namespace std;
int main(int argc, char** argv){
    HashTable<int, int> t;
    std::uniform_int_distribution<int> distribution(1, 100);
    std::random_device rd; 
    std::mt19937 gen(rd());
    
    vector<pair<int,int>> numbers;
    // Generate random numbers
    for (int i = 0; i < 1000; ++i) {
        int key = i;
        int val = distribution(gen);
        numbers.push_back(make_pair(key, val));

        if (i % 2 == 0){
            t[key] = val;
        }
        else{
            t.insert(key, val);
        }
    }

    for (size_t i = 0; i < numbers.size(); ++i) {
        if (t[numbers[i].first] != numbers[i].second){
            cout<<"ERROR"<<endl;
            cout<<"HashTable"<<endl;
            cout<<"KEY "<< numbers[i].first << " Value" << t[numbers[i].first]<<endl;
            cout<<"CORRECT"<<endl;
            cout<<"KEY "<< numbers[i].first << " Value" << numbers[i].second<<endl;
        }
    }

    //t.printTable();
    return 0;
}
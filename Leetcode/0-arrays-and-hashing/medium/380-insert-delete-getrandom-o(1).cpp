/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class RandomizedSet {

    unordered_map<int, int> numberToIndex;
    vector<int> arr;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(numberToIndex.find(val) != numberToIndex.end()) return false;

        arr.push_back(val);
        int index = arr.size() - 1;
        numberToIndex[val] = index;

        return true;
    }
    
    bool remove(int val) {
        if(numberToIndex.find(val) == numberToIndex.end()) return false;

        int targetIndex = numberToIndex[val];

        int endIndex = arr.size() - 1;
        int endVal = arr[endIndex];

        swap(arr[targetIndex], arr[endIndex]);

        numberToIndex[val] = endIndex;
        numberToIndex[endVal] = targetIndex;

        numberToIndex.erase(val);
        arr.pop_back();
 
        return true;
    }
    
    int getRandom() {

        int min = 0;
        int max = arr.size() - 1;

        int range = max - min + 1;
        int index = rand() % range + min;

        return arr[index];
        
    }
};
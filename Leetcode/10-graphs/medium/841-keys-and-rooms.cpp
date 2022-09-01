/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void collectKeys(int i, vector<vector<int>>& rooms, unordered_set<int> &keys) {
        for(int key : rooms[i]) {
            if(keys.find(key) != keys.end()) continue;
            keys.insert(key);
            collectKeys(key, rooms, keys);
        }
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> keys;
        keys.insert(0);
        collectKeys(0, rooms, keys);
        return keys.size() == rooms.size();
    }
};
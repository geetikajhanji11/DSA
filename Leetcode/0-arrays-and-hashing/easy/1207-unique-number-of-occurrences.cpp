/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;

        for(int num : arr) freq[num]++;

        unordered_set<int> s;
        for(auto kv : freq) {
            if(s.find(kv.second) != s.end()) return false;
            s.insert(kv.second);
        }

        return true;
    }
};
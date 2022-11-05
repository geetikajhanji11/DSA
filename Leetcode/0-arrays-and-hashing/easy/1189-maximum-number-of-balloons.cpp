/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {

        string balloon = "balloon";
        unordered_map<char, int> count;
        for(char ch : balloon) count[ch]++;

        unordered_map<char, int> freq;
        for(char ch : text) freq[ch]++;

        int result = INT_MAX;
        for(auto kv : freq) {
            if(count[kv.first] != 0) {
                result = min(result, kv.second / count[kv.first]);
            }
            count.erase(kv.first);
        }

        if(result == INT_MAX) return 0;
        if(count.size() != 0) return 0;
        
        return result;
    }
};
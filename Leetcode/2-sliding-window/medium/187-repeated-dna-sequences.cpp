/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Without using substring on OVERALL string
// sliding window
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 10) return {};

        unordered_map<string, int> count;
        string curr = s.substr(0, 10);
        count[curr]++;

        for(int i=1; i<=s.length()-10; i++) {
            curr.push_back(s[i+9]);
            curr = curr.substr(1, 10);
            count[curr]++;
        }

        vector<string> result;
        for(auto kv : count) {
            if(kv.second > 1) {
                result.push_back(kv.first);
            } 
        }

        return result;
    }
};

// Using substring
// sliding window
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if(s.length() <= 10) return {};

        unordered_map<string, int> count;
        for(int i=0; i<=s.length()-10; i++) {
            string curr = s.substr(i, 10);
            count[curr]++;
        }

        vector<string> result;
        for(auto kv : count) {
            if(kv.second > 1) {
                result.push_back(kv.first);
            } 
        }

        return result;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        
        unordered_map<string, int> count;
        string token;

        stringstream ss1(s1);
        while(getline(ss1, token, ' ')) {
            count[token]++;
        }

        stringstream ss2(s2);
        while(getline(ss2, token, ' ')) {
            count[token]++;
        }

        vector<string> result;
        for(auto kv : count) {
            if(kv.second == 1) {
                result.push_back(kv.first);
            }
        }

        return result;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> getMap(string &s) {
        vector<int> m(26, 0);
        for(char ch : s) {
            m[ch - 'a']++;
        }
        return m;
    }

    bool isUniversal(string &s, vector<int> &overallMap) {
        vector<int> m = getMap(s);
        for(int i=0; i<26; i++) {
            if(m[i] < overallMap[i]) return false;
        }
        return true;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> overallMap(26, 0);
        
        for(string s : words2) {
            vector<int> word2Map = getMap(s);
            for(int i=0; i<26; i++) {
                overallMap[i] = max(overallMap[i], word2Map[i]);
            }
        }

        vector<string> result;
        for(string s : words1) {
            if(isUniversal(s, overallMap)) {
                result.push_back(s);
            }
        }

        return result;
    } 
};
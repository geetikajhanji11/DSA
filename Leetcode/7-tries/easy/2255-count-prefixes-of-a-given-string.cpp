/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        
        int ctr = 0;
        for(string word : words) {
            if(word.length() > s.length()) continue;
            
            bool isPrefix = true;
            for(int i=0; i<word.length(); i++) {
                if(word[i] != s[i]) {
                    isPrefix = false;
                    break;
                }
            }

            if(isPrefix) ctr++;
        }
        return ctr;
    }
};
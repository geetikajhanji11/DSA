/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        if(s.length() < p.length()) return {};
        
        vector<int> pMap(26, 0);
        vector<int> sMap(26, 0);

        // filling up pMap
        for(int i=0; i<p.length(); i++) {
            pMap[p[i] - 'a']++;
        }

        // filling up inital sMap (upto length of p)
        for(int i=0; i<p.length(); i++) {
            sMap[s[i] - 'a']++;
        }

        // counting initial matches
        // O(1)
        int matches = 0;
        for(int i=0; i<26; i++) {
            if(sMap[i] == pMap[i]) {
                matches++;
            }
        }

        // sliding window
        int left = 0;
        int right = p.length() - 1;

        vector<int> result;
        
        while(right < s.length()) {

            if(matches == 26) {
                result.push_back(left);
            }

            // add [right + 1] character
            right++;
            if(right == s.length()) break;

            int rightIdx = s[right] - 'a';
            sMap[rightIdx]++;
            if(sMap[rightIdx] - 1 == pMap[rightIdx]) matches--;
            else if(sMap[rightIdx] == pMap[rightIdx]) matches++;

            // delete [left] character
            int leftIdx = s[left] - 'a';
            sMap[leftIdx]--;
            if(sMap[leftIdx] + 1 == pMap[leftIdx]) matches--;
            else if(sMap[leftIdx] == pMap[leftIdx]) matches++;

            left++;

        }

        return result;
    }
};
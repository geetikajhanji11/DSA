/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> codes;

        int right = 0;
        string currCode = "";

        while(right < s.length()) {
            currCode.push_back(s[right]);

            if(currCode.length() == k) {
                codes.insert(currCode);
                currCode = currCode.substr(1, currCode.length()-1);
            }

            right++;
        }

        // 2^k
        return codes.size() == 1<<k;
    }
};
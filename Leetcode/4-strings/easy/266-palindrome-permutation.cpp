/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPermutePalindrome(string &s) {
        unordered_map<char, int> count;

        for(char ch : s) {
            count[ch]++;
        }

        int countOdds = 0;
        for(auto kv : count) {
            if(kv.second % 2 != 0) countOdds++;
        } 

        return (countOdds == 0 || countOdds == 1);
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> count;

        for(char ch : magazine) count[ch]++;

        for(char ch : ransomNote) {
            if(count[ch] <= 0) return false;
            count[ch]--;
        }

        return true;
    }
};
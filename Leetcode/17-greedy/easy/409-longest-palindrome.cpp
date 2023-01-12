/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for(char ch : s) {
            freq[ch]++;
        }

        int odds = 0;
        for(auto kv : freq) {
            if(kv.second % 2 != 0) {
                odds++;
            }
        }

        int result = s.length();
        
        // odds = total number of odd characters
        // +1 = keep one character of any odd
        if(odds > 1) {
            result = s.length() - odds + 1;
        }
        return result;
    }
};
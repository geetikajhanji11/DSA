/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPalindromicSubsequence(string s) {

        int n = s.length();
        unordered_map<char, pair<int, int>> charStartEnd;

        // O(26*N)
        for(int i=0; i<26; i++) {
            char ch = 'a' + i;

            int startIdx = 0;
            while(startIdx < n && s[startIdx] != ch) startIdx++;

            int lastIdx = n - 1;
            while(lastIdx >= 0 && s[lastIdx] != ch) lastIdx--;

            if(lastIdx - startIdx + 1 >= 3) {
                charStartEnd.insert({ch, {startIdx, lastIdx}});
            }
        }

        // O(26*N)
        int result = 0;
        for(auto kv : charStartEnd) {
            char ch = kv.first;
            int startIdx = kv.second.first;
            int lastIdx = kv.second.second;
            unordered_set<char> uniqueMiddleChars;

            for(int i=startIdx+1; i<=lastIdx-1; i++) {
                uniqueMiddleChars.insert(s[i]);
            }

            result += uniqueMiddleChars.size();
        }

        return result;
    }
};

int main() {

    return 0;
}
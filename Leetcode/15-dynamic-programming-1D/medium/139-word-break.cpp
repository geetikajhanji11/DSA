/*******************************************************************
Given a string & dictionary, return true if:
Can segment string into 1 or more dictionary words

DP, at each loop, substring, check if in dict, & store

Time: O(n^3)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool wordBreak(string s, vector<string>& wordDict) {
    int n = s.length();
    vector<bool> dp(n+1, false);
    dp[n] = true;

    for(int i=n-1; i>=0; i--) {
        for(string word : wordDict) {
            if(i + word.length() > n) continue; // index out of bounds for substring generation
            string substring = s.substr(i, word.length());
            if(substring == word) dp[i] = dp[i + word.length()];
            if(dp[i]) break;
        }
    }
    return dp[0];
}

int main() {

    // vector<string> wordDict = {"leet", "code"};
    // cout<<wordBreak("leetcode", wordDict);

    vector<string> wordDict = {"apple", "pen"};
    cout<<wordBreak("applepenapple", wordDict);
    return 0;
}
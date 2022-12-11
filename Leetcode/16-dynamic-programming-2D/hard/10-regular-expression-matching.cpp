/*******************************************************************
Given string & pattern, implement RegEx matching
'.' -> matches any single character
'*' -> matches zero or more of the preceding element
Matching should cover the entire input string (not partial)
Ex. s = "aa", p = "a" -> false, "a" doesn't match entire string "aa"

DFS + memo, 2 choices at a *: either use it, or don't use it

Time: O(m x n)
Space: O(m x n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, string& s, string& p, map<pair<int, int>, bool> &dp) {
    
    if (dp.find({i, j}) != dp.end()) return dp[{i, j}];
    if (i >= s.size() && j >= p.size()) return true;
    if (j >= p.size()) return false;
    
    bool match = i < s.size() && (s[i] == p[j] || p[j] == '.');
    if (j + 1 < p.size() && p[j + 1] == '*') {
        bool dont_use_star = dfs(i, j+2, s, p, dp);
        bool use_star = match && dfs(i+1, j, s, p, dp);
        dp[{i, j}] = dont_use_star || use_star;
        return dp[{i, j}];
    }
    
    if (match) {
        dp[{i, j}] = dfs(i+1, j+1, s, p, dp);
        return dp[{i, j}];
    }
    
    dp[{i, j}] = false;
    return dp[{i, j}];
}

bool isMatch(string s, string p) {
    map<pair<int, int>, bool> dp;
    return dfs(0, 0, s, p, dp);
}




int main() {

    string s = "ab";
    string p = ".*";
    cout<<isMatch(s, p);
    return 0;
}
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool dfs(int i, int j, string &s, string &p, map<pair<int, int>, bool> &dp) {
    if(dp.find({i, j}) != dp.end()) return dp[{i, j}];
    if(i == s.length() && j == p.length()) return true;
    if(j == p.length()) return false;
    if(i == s.length()) {
        while(j < p.length()) {
            if(p[j] != '*') return dp[{i, j}] = false;
            j++;
        }
        return dp[{i, j}] = true;
    }

    if(s[i] == p[j]) 
        return dp[{i, j}] = dfs(i+1, j+1, s, p, dp);

    if(p[j] == '?') 
        return dp[{i, j}] = dfs(i+1, j+1, s, p, dp);

    if(p[j] == '*') {
        bool dont_use_star = dfs(i, j+1, s, p, dp);
        bool use_star = dfs(i+1, j, s, p, dp);
        return dp[{i, j}] = dont_use_star || use_star;
    }

    return dp[{i, j}] = false;
}

bool isMatch(string s, string p) {
    map<pair<int, int>, bool> dp;
    return dfs(0, 0, s, p, dp);
}

int main() {

    return 0;
}
/*******************************************************************
Given 2 strings s & t:
Return # of distinct subsequences of s which equals t
Ex. s = "rabbbit", t = "rabbit" -> 3, RABBbIT, RAbBBIT, RABbBIT

DFS + memo, cache on i & j indices to the # of distinct subseq
2 choices: if chars equal, look at remainder of both s & t
            if chars not equal, only look at remainder of s

Time: O(m x n)
Space: O(m x n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ---------------- TOP-DOWN APPROACH ----------------
int dfs(int i, int j, string &s, string &t, vector<vector<int>> &dp) {

    if(j == t.length()) return 1;
    if(i == s.length()) return 0;

    if(dp[i][j] != -1) return dp[i][j];
    
    int nums = 0;

    if(s[i] == t[j]) {
        nums += dfs(i+1, j+1, s, t, dp);
        nums += dfs(i+1, j, s, t, dp);
    } else {
        nums += dfs(i+1, j, s, t, dp);
    }
    
    return dp[i][j] = nums;

}

int numDistinct(string s, string t) {
    int n1 = s.length();
    int n2 = t.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return dfs(0, 0, s, t, dp);
}

// ---------------- BOTTOM-UP APPROACH ----------------
int numDistinct(string s, string t) {
    int n1 = s.length();
    int n2 = t.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));
    
    for(int i=0; i<=n1; i++) dp[i][n2] = 1;
    for(int j=0; j<=n2; j++) dp[n1][j] = 0;
    dp[n1][n2] = 1;

    for(int i=n1-1; i>=0; i--) {
        for(int j=n2-1; j>=0; j--) {
            if(s[i] == t[j]) {
                dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
            } else {
                dp[i][j] = dp[i+1][j];
            }
        }
    }
    return dp[0][0];  
}

int main() {

    string s = "rabbbit";
    string t = "rabbit";
    cout<<numDistinct(s, t);

    return 0;
}
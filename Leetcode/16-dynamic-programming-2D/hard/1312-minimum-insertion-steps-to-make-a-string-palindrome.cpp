/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************ TOP-DOWN APPROACH ************
class Solution {

    int minimumInserts(int i, int j, string &s, vector<vector<int>> &dp) {

        // base case
        if(i >= j) return 0;

        // already computed
        if(dp[i][j] != -1) return dp[i][j];

        // already equal
        // go to next iteration
        if(s[i] == s[j]) {
            return dp[i][j] = minimumInserts(i+1, j-1, s, dp);
        }

        // insert s[j] before s[i]
        // m  [d]  b   d   d   m
        //         i       j
        int insert1 = 1 + minimumInserts(i, j-1, s, dp);
        
        // insert s[i] after s[j]
        // m    b   d   d  [b]  m
        //      i       j
        int insert2 = 1 + minimumInserts(i+1, j, s, dp);

        return dp[i][j] = min(insert1, insert2);
    }

public:
    int minInsertions(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
        return minimumInserts(0, s.length()-1, s, dp);
    }
};

// ************ BOTTOM-UP APPROACH ************
// Same as longest palindrome subsequence
class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();

        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                if(s[i-1] == rev_s[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return n - dp[n][n];
    }
};
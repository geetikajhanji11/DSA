/*******************************************************************
Given 2 strings, return minimum number of operations to convert word1 to word2

Naive: check all possible edit sequences & choose shortest one
Optimal: DP, if chars at i & j same, no operations needed, else 3 cases:
(1) replace (i - 1, j - 1), 
(2) delete (i - 1, j), 
(3) insert (i, j - 1)

Time: O(m x n)
Space: O(m x n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// --------------- TOP-DOWN APPROACH --------------- 
int dfs(int i, int j, string &word1, string &word2, vector<vector<int>> &dp) {
    if(i == word1.length()) return word2.length() - j;
    if(j == word2.length()) return word1.length() - i;

    if(dp[i][j] != -1) return dp[i][j];

    int operations = 0;
    if(word1[i] == word2[j]) {  
        return dp[i][j] = dfs(i+1, j+1, word1, word2, dp); // no operation performed
    } else {
        int op1 = 1 + dfs(i+1, j, word1, word2, dp); //delete
        int op2 = 1 + dfs(i+1, j+1, word1, word2, dp); // replace
        int op3 = 1 + dfs(i, j+1, word1, word2, dp); // insert
        int min_op = min(op1, min(op2, op3));
        operations = min_op;
    }

    return dp[i][j] = operations;
}

int minDistance(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    vector<vector<int>> dp(n1, vector<int>(n2, -1));
    return dfs(0, 0, word1, word2, dp);
}

// --------------- BOTTOM-UP APPROACH --------------- 
int minDistance(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    vector<vector<int>> dp(n1+1, vector<int>(n2+1, 0));

    // base case: word2 is ""
    for(int i=0; i<=n1; i++) {
        dp[i][n2] = n1 - i;
    }

    // base case: word1 is ""
    for(int j=0; j<=n2; j++) {
        dp[n1][j] = n2 - j;
    }

    // check
    for(int i=n1-1; i>=0; i--) {
        for(int j=n2-1; j>=0; j--) {
            if(word1[i] == word2[j]) {
                dp[i][j] = dp[i+1][j+1];
            } 
            else {
                int insert_cost = dp[i][j+1];
                int replace_cost = dp[i+1][j+1];
                int delete_cost = dp[i+1][j];
                int min_cost = min(insert_cost, min(replace_cost, delete_cost));
                dp[i][j] = 1 + min_cost;
            }
        }
    }

    return dp[0][0];
}

int main() {

    string word1 = "horse";
    string word2 = "ros";
    cout<<minDistance(word1, word2);
    return 0;
}
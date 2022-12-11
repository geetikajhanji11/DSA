/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ---------------- TOP-DOWN APPROACH ----------------
/*
bool in_bounds(int i, int j, int m, int n) {
    return i >= 0 && i < m && j >= 0 && j < n;
}
int all_paths(int i, int j, int m, int n, vector<vector<int>> &dp) {
    if(i == m-1 && j == n - 1) return 1;
    if(!in_bounds(i, j, m, n)) return 0;

    if(dp[i][j] != 0) return dp[i][j];

    int down_paths = all_paths(i+1, j, m, n, dp);
    int right_paths = all_paths(i, j+1, m, n, dp);

    return dp[i][j] = down_paths + right_paths;
}
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    return all_paths(0, 0, m, n, dp);
}
*/

// ---------------- BOTTOM-UP APPROACH ----------------
int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

    // fill last row with 0
    for(int j=0; j<=n; j++) dp[m][j] = 0;

    // fill last col with 0
    for(int i=0; i<=m; i++) dp[i][n] = 0;

    // the goal position has value 1
    dp[m-1][n-1] = 1;

    // logic
    for(int i=m-1; i>=0; i--) {
        for(int j=n-1; j>=0; j--) {
            dp[i][j] += dp[i+1][j] + dp[i][j+1];
        }
    }

    return dp[0][0];
}

int main() {

    cout<<uniquePaths(3, 7);
    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* TOP - DOWN APPROACH ************* 
int minNumberOfSquares(int n, vector<int> &perfectSquares, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    int ans = INT_MAX;
    for(int square : perfectSquares) {
        if(n - square < 0) break;
        int remaining = minNumberOfSquares(n-square, perfectSquares, dp);
        ans = min(ans, remaining);
    }

    return dp[n] = ans + 1;
}

int numSquares(int n) {
    vector<int> perfectSquares;
    for(int i=1; i<=99; i++) {
        perfectSquares.push_back(i*i);
    }

    vector<int> dp(n+1, -1);
    int ans = minNumberOfSquares(n, perfectSquares, dp);
    return ans;
}

// ************* BOTTOM - UP APPROACH ************* 
int numSquares(int n) {
    vector<int> dp(n+1);
    for(int i=0; i<=n; i++) dp[i] = i; 
    
    for(int target=1; target<=n; target++) {
        for(int i=1; i<=target; i++) {
            int square = i * i;
            if(target - square < 0) break; 
            dp[target] = min(dp[target], 1 + dp[target-square]);
        }
    }
    return dp[n];
}

int main() {

    return 0;
}
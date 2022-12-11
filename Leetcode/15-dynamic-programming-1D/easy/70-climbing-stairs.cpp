/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int climb(int i, int n, vector<int> &dp) {

    if(i == n) return 1;
    if(i > n) return 0;

    if(dp[i] != -1) return dp[i];

    int one = climb(i+1, n, dp);
    int two = climb(i+2, n, dp);

    int total = one + two;
    return dp[i] = total; 
}

int climbStairs(int n) {
    vector<int> dp(n+1, -1);
    int ans = climb(0, n, dp);
    return ans;
}


int main() {

    return 0;
}
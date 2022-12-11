/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int count_bst(int n, vector<int> &dp) {
    if(n == 0 || n == 1) return 1;

    if(dp[n] != 0) return dp[n];

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int left_subtrees = count_bst(i-1, dp);
        int right_subtrees = count_bst(n-i, dp);
        ans += left_subtrees * 1 * right_subtrees;
    } 

    return dp[n] = ans;
}

int numTrees(int n) {
    vector<int> dp(n+1, 0);
    return count_bst(n, dp);
}

int main() {

    return 0;
}
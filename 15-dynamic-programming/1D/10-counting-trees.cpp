/*******************************************************************
 * COUNTING TREES
 * 
 * Count the number of Binary Search Trees that can be formed
 * using N nodes, numbered from 1 to N.
 * 
 * Sample Input
 *      3
 *      4
 * 
 * Sample Output
 *      5
 *      14
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top-down approach
int count_bst(int n, vector<int> &dp) {
    if(n == 0 || n == 1) return 1;

    if(dp[n] != 0) return dp[n];

    int ans = 0;
    for(int i=1; i<=n; i++) {
        int left = count_bst(i-1, dp);
        int right = count_bst(n-i, dp);
        ans += left * 1 * right;
    }

    dp[n] = ans;
    return ans;
}

// bottom-up approach
int count_bst(int n) {

    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2; i<=n; i++) {
        int ans = 0;
        for(int j=1; j<=i; j++) {
            ans += (dp[j-1] * dp[i-j]);
        }   
        dp[i] = ans;
    }

    return dp[n];
}


int main() {

    int n = 5;
    vector<int> dp(n+1, 0);
    cout<<"\nTop-Down = "<<count_bst(n, dp);
    cout<<"\nBottom-Up = "<<count_bst(n);
    return 0;
}
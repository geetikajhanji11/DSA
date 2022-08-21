/*******************************************************************

------------- MY ORIGINAL CODE -------------
------ Works, but it is not optimized ------

int combinations(int i, int lastMax, int ctr_k, int n, int k, vector<bool> visited, int elements) {
    if(elements == n && ctr_k == k) return 1;

    if(ctr_k > k) return 0;

    visited[i] = true;

    int ans = 0;
    for(int j=1; j<=n; j++) {
        if(visited[j]) continue;
        if(j > lastMax) {
            ans += combinations(j, j, ctr_k+1, n, k, visited, elements + 1);
        } else {
            ans += combinations(j, lastMax, ctr_k, n, k, visited, elements + 1);
        }
    }

    visited[i] = false;

    return ans;
}

int rearrangeSticks(int n, int k) {
    vector<bool> visited(n+1, false);
    int ans = 0;
    for(int i=1; i<=n; i++) {
        ans += combinations(i, i, 1, n, k, visited, 1);
    }
    return ans;
}

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// --------------- TOP-DOWN APPROACH ---------------
// TLE but logic is correct
int combinations(int n, int k, vector<vector<int>> dp) {

    // only 1 way
    if(n == k) return 1;

    // impossible to rearrange sticks
    if(n == 0 || k == 0) return 0;

    if(dp[n][k] != -1) return dp[n][k];

    // putting largest stick in last position
    // this will be visible always
    int op1 = combinations(n-1, k-1, dp);

    // putting any of the remaining sticks (n-1)
    // in the last position
    // this will not be visible
    int op2 = (n-1) * combinations(n-1, k, dp);

    return dp[n][k] = (op1 + op2) % 1000000007;
}

int rearrangeSticks(int n, int k) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    int ans = combinations(n, k, dp);
    return ans % 1000000007;
}

// --------------- BOTTOM-UP APPROACH ---------------
// only one that works
int rearrangeSticks(int n, int k) {
    vector<vector<long long int>> dp(n+1, vector<long long int>(k+1, 0));
    dp[1][1] = 1;

    for(int N=2; N<=n; N++) {
        for(int K=1; K<=k; K++) {
            long long int op1 = dp[N-1][K-1];
            long long int op2 = (N-1) * dp[N-1][K];
            dp[N][K] = (op1 + op2) % 1000000007;
        }
    }

    return dp[n][k] % 1000000007;
}

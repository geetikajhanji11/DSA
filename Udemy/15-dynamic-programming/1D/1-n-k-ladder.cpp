/*******************************************************************
N-K LADDER PROBLEMS

Given a ladder of size n and an integer k, write a function to 
compute the number of ways to climb the ladder if you can take a
jump of at most k steps.

Input: 
    N = 4
    K = 3

Output:
    7
*******************************************************************/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ***** SOLUTION - 1 ****** 
// top-down approach
int climb_ladder(int n, int k, vector<int> &dp) {
    if(n == 0) return 1;
    if(n < 0) return 0;
    if(dp[n] != 0) return dp[n];

    int steps = 0;
    for(int jump=1; jump<=k; jump++) {
        steps += climb_ladder(n-jump, k, dp);
    }

    dp[n] = steps;
    return dp[n];
}

// bottom-up approach
int climb_ladder(int n, int k) {
    vector<int> dp(n+1, 0);
    
    dp[0] = 1;
    int sum = dp[0];

    // fill up dp from [1] to [k]
    for(int i=1; i<=k; i++) {
        dp[i] = sum;
        sum += dp[i];
    }

    // fill up dp from [k] to [n]

    /****** SOLUTION - 2 ****** 
    // O(NK)
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++) {
            if(i-j < 0) break;
            dp[i] += dp[i-j];
        }
    }
    */

    //***** SOLUTION - 3 ***** 
    // O(N)
    // Fill from [k+1] to [n]
    for(int i=k+1; i<=n; i++) {
        int window_sum = dp[i-1];
        int subtract = dp[i-(k+1)];
        int add = dp[i-1];
        int next_term = window_sum - subtract + add;
        dp[i] = next_term;
    }

    return dp[n];
}

int main() {

    int n = 4;
    int k = 3;

    vector<int> dp(n+1, 0);
    cout<<"\nTop-Down = "<<climb_ladder(n, k, dp);
    cout<<"\nBottom-Up = "<<climb_ladder(n, k);

    return 0;
}
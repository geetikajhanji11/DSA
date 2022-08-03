/*******************************************************************
 * FROG MIN COST
 * 
 * There are N stones given in the form of an array, each element
 * in an array represents the height of its stone. There is a frog
 * who is initially on Stone 1.
 * Frog will repeat the following action some number of times to 
 * reach Stone N :-
 *      If the frog is currently on Stone i, jump to Stone i+1, 
 *      i+2, ..., i+k. Here, a cost of |hi - hj| is incurred, where
 *      j is the stone to land on.
 * Find the minimum possible total cost incurred before the frog
 * reaches Stone N.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** TOP - DOWN APPROACH ***************
int min_cost_helper(int i, int k, vector<int> stones, vector<int> &dp) {

    // base cases
    if(i == stones.size() - 1) return 0;
    if(i >= stones.size()) return INT_MAX;

    // rec case
    if(dp[i] != 0) return dp[i];

    int ans = INT_MAX;

    for(int height=1; height<=k; height++) {
        int jump_cost = min_cost_helper(i+height, k, stones, dp);
        int sum = jump_cost;
        if(jump_cost != INT_MAX) {
            sum = jump_cost + (abs(stones[i] - stones[i+height]));
        }
        ans = min(ans, sum);
    }

    dp[i] = ans;
    return dp[i];
    
}

long long minimumCost(vector<int> stones, int k){
    vector<int> dp(stones.size(), 0);
    return min_cost_helper(0, k, stones, dp);
}

// *************** BOTTOM - UP APPROACH ***************
long long minimumCost(vector<int> stones, int k){

    int n = stones.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--) {

        int ans = dp[i];
        for(int jump=1; jump<=k; jump++) {
            if(i + jump >= n) break;
            int cost = dp[i+jump];
            if(cost != INT_MAX) {
                cost += abs(stones[i] - stones[i+jump]);
            }
            ans = min(ans, cost);
        }
        dp[i] = ans;
    }

    return dp[0];
}

int main() {

    vector<int> stones = {10, 30, 40, 50, 20};
    int k = 3;

    cout<<"\nTop-Down = "<<minimumCost(stones, k);
    return 0;
}
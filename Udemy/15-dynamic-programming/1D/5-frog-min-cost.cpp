/*******************************************************************
 * FROG MIN COST
 * 
 * There are N stones given in the form of an array, each element
 * in an array represents the height of its stone. There is a frog
 * who is initially on Stone 1.
 * Frog will repeat the following action some number of times to 
 * reach Stone N :-
 *      If the frog is currently on Stone i, jump to Stone i+1
 *      to Stone i+2. Here, a cost of |hi - hj| is incurred, where
 *      j is the stone to land on.
 * Find the minimum possible total cost incurred before the frog
 * reaches Stone N.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*

**************** TOP - DOWN ****************
int min_cost(int i, vector<int> &stones, vector<int> &dp) {

    if(i == stones.size() - 1) return 0;
    if(i >= stones.size()) return INT_MAX;

    if(dp[i] != INT_MAX) return dp[i];

    int ans = INT_MAX;

    int jump_1 = min_cost(i+1, stones, dp);
    int jump_2 = min_cost(i+2, stones, dp);
  
    if(jump_1 != INT_MAX) {
        jump_1 += abs(stones[i] - stones[i+1]);
    } 
    if(jump_2 != INT_MAX) {
        jump_2 += abs(stones[i] - stones[i+2]);
    }

    ans = min(jump_1, jump_2);

    return dp[i] = ans;
}

**************** BOTTOM - UP ****************
int min_cost(vector<int> &stones) {
    
    int n = stones.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--) {
        int ans = dp[i];
        
        int jump_1 = INT_MAX;
        int jump_2 = INT_MAX;
        
        if(i+1 < n) jump_1 = dp[i+1];
        if(i+2 < n) jump_2 = dp[i+2];

        if(jump_1 != INT_MAX) jump_1 += abs(stones[i] - stones[i+1]);
        if(jump_2 != INT_MAX) jump_2 += abs(stones[i] - stones[i+2]);  

        dp[i] = min(jump_1, jump_2);
    }

    return dp[0];
}
*/

// top - down approach
int min_cost(int i, vector<int> stones, vector<int> &dp) {

    // base cases
    if(i == stones.size() - 1) return 0;
    if(i >= stones.size()) return INT_MAX;

    // rec case
    if(dp[i] != 0) return dp[i];

    int ans = INT_MAX;
    int jump_1_cost = min_cost(i+1, stones, dp);
    int jump_2_cost = min_cost(i+2, stones, dp);

    // sum_1 won't be out of bounds ever
    int sum_1 = jump_1_cost + (abs(stones[i] - stones[i+1]));

    // since i+2 can be out of bounds,
    // so if it is out of bounds, we assign INT_MAX
    int sum_2 = INT_MAX;
    if(jump_2_cost != INT_MAX) {
        sum_2 = jump_2_cost + (abs(stones[i] - stones[i+2]));
    }

    dp[i] = min(sum_1, sum_2);
    return dp[i];
    
}

// bottom-up approach
int min_cost(vector<int> stones) {

    vector<int> dp(stones.size(), 0);

    dp[0] = 0;
    dp[1] = abs(stones[1] - stones[0]) + dp[0];

    for(int i=2; i<stones.size(); i++) {
        int cost_1 = abs(stones[i] - stones[i-1]) + dp[i-1];
        int cost_2 = abs(stones[i] - stones[i-2]) + dp[i-2];
        dp[i] = min(cost_1, cost_2);
    }

    return dp[stones.size() - 1];
}

int main() {

    vector<int> stones = {30, 10, 60, 10, 60, 50};
    // vector<int> stones = {10, 30, 40, 20};
    vector<int> dp(stones.size(), 0);

    cout<<"\nTop-Down = "<<min_cost(0, stones, dp);
    cout<<"\nBottom-Up = "<<min_cost(stones);
    return 0;
}
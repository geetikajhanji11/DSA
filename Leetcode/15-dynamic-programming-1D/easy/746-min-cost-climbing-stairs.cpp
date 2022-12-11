/*******************************************************************
Given cost array, ith step is cost[i], can climb 1 or 2 steps
Return min cost to reach top floor, can start at index 0 or 1
Ex. cost = [10,15,20] -> 15, start at idx 1, pay 15, climb 2

Recursion w/ memoization -> DP, min cost to reach 1/2 steps below curr step
Recurrence relation: 
    minCost[i] = min(minCost[i-1] + cost[i-1], minCost[i-2] + cost[i-2])

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ---------------- TOP-DOWN APPROACH ----------------
int min_cost(int i, vector<int>& cost, vector<int> &dp) {

    if(i >= cost.size()) return 0;
    if(dp[i] != -1) return dp[i];

    int cost_1 = min_cost(i+1, cost, dp);
    int cost_2 = min_cost(i+2, cost, dp);

    int curr_cost = 0; 
    if(cost_1 <= cost_2) {
        curr_cost = cost[i] + cost_1;
    } else {
        curr_cost = cost[i] + cost_2;
    }

    dp[i] = curr_cost;
    return curr_cost;
}


int minCostClimbingStairs(vector<int>& cost) {

    // have to do this because it said that 
    // can jump from index 0 or 1 only
    // cannot use -1, because indexing would be messed up
    // so added a new value 0 in te beginning itself
    // so that cost addition is also not messed up
    cost.insert(cost.begin() + 0, 0);  
    
    vector<int> dp(cost.size()+1, -1);
    int ans = min_cost(0, cost, dp);

    return ans;
}

// ---------------- BOTTOM-UP APPROACH ----------------
int minCostClimbingStairs(vector<int>& cost) {

    int n = cost.size();

    int jump_1_cost = 0;
    int jump_2_cost = 0;
    
    for(int i=n-1; i>=0; i--) {
        jump_1_cost = cost[i] + (i+1 < n ? cost[i+1] : 0);
        jump_2_cost = cost[i] + (i+2 < n ? cost[i+2] : 0);
        cost[i] = min(jump_1_cost, jump_2_cost);
    }

    return min(cost[0], cost[1]);
}

int main() {

    return 0;
}
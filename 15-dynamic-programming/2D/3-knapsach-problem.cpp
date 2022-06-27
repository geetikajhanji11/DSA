/*******************************************************************
 * KNAPSACK PROBLEM
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int knapsack_top_down(int i, int curr_weight, vector<int> prices, vector<int> weights, vector<vector<int>> &dp) {

    // base case
    if(i == 0 || curr_weight == 0) return 0;

    // already computed
    if(dp[i][curr_weight] != 0) return dp[i][curr_weight];

    // rec case
    int include_profit = 0;
    if(weights[i-1] <= curr_weight) {
        include_profit = prices[i-1] + knapsack_top_down(i-1, curr_weight - weights[i-1], prices, weights, dp);
    }
    int exclude_profit = knapsack_top_down(i-1, curr_weight, prices, weights, dp);

    return dp[i][curr_weight] = max(include_profit, exclude_profit);
}

int knapsack_bottom_up(int n, int w, vector<int> prices, vector<int> weights) {

   vector<vector<int>> dp(n+1, vector<int>(w+1, 0));

   for(int i=1; i<=n; i++) {
    for(int curr_weight=1; curr_weight<=w; curr_weight++) {
        int include_profit = 0;
        int exclude_profit = 0;
        if(weights[i-1] <= curr_weight) {
            include_profit = prices[i-1] + dp[i-1][curr_weight - weights[i-1]];
        }
        exclude_profit = dp[i-1][curr_weight];

        dp[i][curr_weight] = max(include_profit, exclude_profit);
    }
   }

   return dp[n][w];
}

int main() {

    vector<int> weights = {2, 7, 3, 4};
    vector<int> prices = {5, 20, 20, 10};
    int n = weights.size();
    int w = 11;

    vector<vector<int>> dp(n+1, vector<int>(w+1, 0));
    cout<<"\nTop-Down DP = "<<knapsack_top_down(n, w, prices, weights, dp);

    cout<<"\nBottom-Up DP = "<<knapsack_bottom_up(n, w, prices, weights);

    return 0;
}
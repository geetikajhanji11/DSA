/*******************************************************************
 * COIN CHANGE - 2
 * 
 * Given a value N and an integer vector COINS representing coins
 * of different denominations. Considering you have infinite supply
 * of each coin, your task is to find the total number of combinations
 * of these coins that make a sum of N.
 * 
 * If that amount of money cannot be made up by any combination of
 * the coins, return 0.
 * 
 * Input:
 *      n = 4
 *      coins = {1, 2, 3, 4}
 * 
 * Ouput:
 *      4
 *      
 * Explanation:
 *      {1, 1, 1, 1}, 
 *      {1, 1, 2},
 *      {1, 3},
 *      {2, 2}
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** top-down approach **************
// i => index of current coin
// curr_sum => current sum of combination
long long coin_change(int i, int curr_sum, vector<int> coins, vector<vector<long long>> &dp) {

    // if index is out of bounds and function has not
    // returned 1 yet (found an answer) 
    // OR
    // the current sum is < 0, which means there is
    // no possible answer for this combination
    if(i >= coins.size() || curr_sum < 0) return 0;

    // if current sum = 0, we found a combination
    if(curr_sum == 0) return 1;

    // check for already computed answer
    if(dp[i][curr_sum] != -1) return dp[i][curr_sum]; 
    
    // include/exclude the current coin in the combination
    long long include = coin_change(i, curr_sum - coins[i], coins,dp);
    long long exclude = coin_change(i+1, curr_sum, coins, dp);
    
    // final answer is sum of both
    return dp[i][curr_sum] = include + exclude;
    
}

long long findCombinations(int n, vector<int> coins) {
    vector<vector<long long>> dp(coins.size()+1, vector<long long>(n+1, -1));
    return coin_change(0, n, coins, dp); 
}

// ************** bottom-up ************** 
// https://www.youtube.com/watch?v=Mjy4hd2xgrs&ab_channel=NeetCode
// TO DO
int findCombinations_BU(int n, vector<int> coins) {
    vector<vector<long long>> dp(coins.size()+1, vector<long long>(n+1, 0));

    for(int i=0; i<=coins.size(); i++) dp[i][0] = 1;

    // rows = coins
    // cols = amount
    for(int i=1; i<=coins.size(); i++) {
        for(int curr_sum=1; curr_sum<=n; curr_sum++) {
            int include = curr_sum - coins[i] >= 0 ? dp[i][curr_sum - coins[i]] : 0;
            int exclude = dp[i-1][curr_sum];
            dp[i][curr_sum] = include + exclude;
        }
    }
    for(auto v : dp) {
        for(int num : v) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return dp[coins.size()][n];
}

int main() {

    vector<int> coins = {1, 2, 5};
    int n = 5;
    cout<<findCombinations(n, coins)<<endl;
    cout<<findCombinations_BU(n, coins);
    return 0;
}
/*******************************************************************
COIN CHANGE

 * Given an array of coin denominations, and integer M representing
 * target money. We need to find the minimum coins required to make
 * the change.
 * 
 * INPUT
 *     coins = [1, 3, 7, 10]
 *     M = 15
 * 
 * OUTPUT
 *     3
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top-down approach
int coin_change(int n, vector<int> coins, vector<int> &dp) {

    // base case
    if(n == 0) return 0;

    // already explored
    if(dp[n] != 0) return dp[n];

    // explore each coin and choose the one
    // which returns min value
    int rem_min_coins = INT_MAX;
    for(int i=0; i<coins.size(); i++) {
        int curr_coin = coins[i];
        if(n - curr_coin < 0) continue;
        rem_min_coins = min(rem_min_coins, coin_change(n-curr_coin, coins, dp));
    }

    // update dp
    dp[n] = rem_min_coins + 1;
    
    // return the final result 
    return dp[n];
}

// bottom up approach
int coin_change(int n, vector<int> coins) {

    vector<int> dp(n+1, 0);

    for(int i=1; i<=n; i++) {
        int curr_min = INT_MAX;
        dp[i] = curr_min;
        for(int coin : coins) {
            int remaining_coins = i - coin;
            if(remaining_coins >= 0 && dp[remaining_coins] != INT_MAX) {
                curr_min = min(curr_min, dp[remaining_coins]);
            }
        }
        dp[i] = curr_min + 1;
    }

    // no such way is possible
    if(dp[n] == INT_MAX) return -1;

    return dp[n];
}

int main() {

    int n = 15;
    vector<int> coins = {1, 3, 7, 10};
    vector<int> dp(n+1, 0); 

    cout<<"\nTop Down = "<<coin_change(n, coins, dp);
    cout<<"\nBottom Up = "<<coin_change(n, coins);

    

    return 0;
}
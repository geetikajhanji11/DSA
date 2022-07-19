/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount+1, amount+1);
    dp[0] = 0;

    for(int curr_amount=1; curr_amount<=amount; curr_amount++) {
        for(int coin : coins) {
            int remaining = curr_amount - coin;
            if(remaining < 0) continue;
            dp[curr_amount] = min(dp[curr_amount], 1 + dp[remaining]);
        }
    }

    return dp[amount] == amount+1 ? -1 : dp[amount];
}

int main() {

    vector<int> coins = {2,3,5,7};
    int amount = 8;

    cout<<coinChange(coins, amount);
    return 0;
}
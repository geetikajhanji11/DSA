/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// -------------- RECURSIVE --------------
/*
int all_ways(int i, int amount, vector<int>& coins) {
    if(i >= coins.size()) return 0;
    if(amount < 0) return 0;
    if(amount == 0) return 1;

    int ways = 0;
    int ways1 = all_ways(i, amount-coins[i], coins); // including current coin
    int ways2 = all_ways(i+1, amount, coins); // excluding current coin
    ways += (ways1 + ways2);

    return ways;

}
int change(int amount, vector<int>& coins) {
    return all_ways(0, amount, coins);
}
*/

// -------------- TOP-DOWN DP --------------
// O(MN)
/*
int all_ways(int i, int amount, vector<int>& coins, vector<vector<int>> &dp) {
    if(i >= coins.size()) return 0;
    if(amount < 0) return 0;
    if(amount == 0) return 1;

    if(dp[i][amount] != -1) return dp[i][amount];

    int ways = 0;
    int ways1 = all_ways(i, amount-coins[i], coins, dp);
    int ways2 = all_ways(i+1, amount, coins, dp);
    ways += ways1 + ways2;

    return dp[i][amount] = ways;

}
int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    return all_ways(0, amount, coins, dp);
}
*/

// -------------- BOTTOM-UP DP --------------
// O(N)
//     5   4   3   2   1   0
// -------------------------
// 1 |                     1
// 2 |                     1 
// 5 |                     1 

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>> dp(amount+1, vector<int>(n+1, 0));

    for(int j=0; j<=n; j++) dp[0][j] = 1;

    for(int curr_amount=1; curr_amount<=amount; curr_amount++){
        for(int j=1; j<=n; j++) {
            dp[curr_amount][j] = dp[curr_amount][j-1];
            if(curr_amount - coins[j-1] >= 0){
                dp[curr_amount][j] += dp[curr_amount-coins[j-1]][j];
            }
        }
    }
    return dp[amount][n];
}


int main() {

    vector<int> coins = {1,2,3,4};
    int amount = 11;
    cout<<change(amount, coins);
    return 0;
}
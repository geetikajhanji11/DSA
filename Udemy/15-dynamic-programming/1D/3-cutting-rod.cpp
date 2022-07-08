/*******************************************************************
CUTTING ROD
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top-down approach
int max_profit(int n, vector<int> prices, vector<int> &dp) {
    if(n == 0) return 0;
    if(dp[n] != 0) return dp[n];

    int profit = INT_MIN;
    for(int cut=1; cut<=n; cut++) {
        int curr_profit = prices[cut] + max_profit(n-cut, prices, dp);
        profit = max(profit, curr_profit);
    }

    dp[n] = profit;
    return dp[n];
}

// bottom-up approach
int max_profit(int n, vector<int> prices) {

    vector<int> dp(n+1, 0);
    
    for(int total_len=1; total_len<=n; total_len++) {
        int profit = INT_MIN;
        for(int cut=1; cut<=total_len; cut++) {
            int curr_profit = prices[cut] + dp[total_len-cut];
            profit = max(profit, curr_profit);
        }
        dp[total_len] = profit;
    }
    return dp[n];
}

int main() {

    vector<int> prices = {0, 3, 5, 8, 9, 10, 17, 17, 20};
    int n = prices.size() - 1;
    vector<int> dp(n+1, 0);

    cout<<"\nTop-Down = "<<max_profit(n, prices, dp);
    cout<<"\nBottom-Up = "<<max_profit(n, prices);
    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int max_profit(int i, bool buying, int tCount, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if(i == prices.size()) return 0;
        if(tCount == 2) return 0;
        if(dp[i][buying][tCount] != -1) return dp[i][buying][tCount];

        int profit = 0;

        if(buying) {
            int buy_profit = -prices[i] + max_profit(i+1, false, tCount, prices, dp);
            int not_buy_profit = max_profit(i+1, true, tCount, prices, dp);
            profit = max(buy_profit, not_buy_profit);
        } else {
            int sell_profit = prices[i] + max_profit(i+1, true, tCount+1, prices, dp);
            int not_sell_profit = max_profit(i+1, false, tCount, prices, dp);
            profit = max(sell_profit, not_sell_profit);
        }

        return dp[i][buying][tCount] = profit;
    }

public:
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1)));
        return max_profit(0, true, 0, prices, dp);
    }
};
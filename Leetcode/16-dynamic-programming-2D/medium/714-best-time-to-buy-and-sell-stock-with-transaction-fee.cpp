/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ****************** TOP-DOWN ******************  
class Solution {

    int max_profit(int i, bool buying, vector<int>& prices, int &fee, vector<vector<int>> &dp) {
        if(i == prices.size()) return 0;
        if(dp[i][buying] != -1) return dp[i][buying];

        int profit = INT_MIN;
        if(buying) {
            int buy_profit = max_profit(i+1, false, prices, fee, dp) - prices[i];
            int not_buy_profit = max_profit(i+1, true, prices, fee, dp);
            profit = max(buy_profit, not_buy_profit);
        } else {
            int sell_profit = max_profit(i+1, true, prices, fee, dp) + prices[i] - fee;
            int not_sell_profit = max_profit(i+1, false, prices, fee, dp);
            profit = max(sell_profit, not_sell_profit);
        }

        return dp[i][buying] = profit;
    }

public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return max_profit(0, true, prices, fee, dp);
    }
};


// ****************** BOTTOM-UP ******************  
class Solution {

public:
    int maxProfit(vector<int>& prices, int fee) {
        int futureBuy = 0;
        int futureSell = 0;

        int currBuy = 0;
        int currSell = 0;

        for(int i=prices.size()-1; i>=0; i--) {

            // selling the current stock
            currSell = max(futureSell, prices[i] - fee + futureBuy);

            // buying the current stock
            currBuy = max(futureBuy, -prices[i] + futureSell);

            futureSell = currSell;
            futureBuy = currBuy;
        }

        return futureBuy;
    }
};
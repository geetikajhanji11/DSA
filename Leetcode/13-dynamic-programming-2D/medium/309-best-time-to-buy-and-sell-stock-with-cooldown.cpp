/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// ------------ TOP-DOWN ------------
int get_max_profit(int i, bool buying, vector<int>& prices, vector<vector<int>> &dp) {
    
    if(i >= prices.size()) return 0;
    if(dp[i][buying] != -1) return dp[i][buying];

    if(buying) {
        int buy_profit = get_max_profit(i+1, false, prices, dp) - prices[i];
        int cooldown_profit = get_max_profit(i+1, true, prices, dp);
        dp[i][buying] = max(buy_profit, cooldown_profit);
    } 

    else {
        int sell_profit = get_max_profit(i+2, true, prices, dp) + prices[i];
        int cooldown_profit = get_max_profit(i+1, false, prices, dp);
        dp[i][buying] = max(sell_profit, cooldown_profit);
    }

    return dp[i][buying];
}

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(n, vector(2, -1));
    return get_max_profit(0, true, prices, dp);
}

// ------------ BOTTOM-UP ------------
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sold = 0;
        int hold = INT_MIN;
        int rest = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            int prevSold = sold;
            sold = hold + prices[i];
            hold = max(hold, rest - prices[i]);
            rest = max(rest, prevSold);
        }
        
        return max(sold, rest);
    }
};

int main() {

    vector<int> prices = {1};
    cout<<maxProfit(prices);
    return 0;
}
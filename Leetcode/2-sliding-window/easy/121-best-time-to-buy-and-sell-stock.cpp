#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int left = 0; // buy
    int right = 1; // sell

    int largest_profit = 0;
    while(right < n) {

        if(prices[left] < prices[right]) {
            int profit = prices[right] - prices[left];
            largest_profit = max(largest_profit, profit);
        } else {
            left = right;
        }
        right++;
    }

    return largest_profit;
}

int main() {

    return 0;
}
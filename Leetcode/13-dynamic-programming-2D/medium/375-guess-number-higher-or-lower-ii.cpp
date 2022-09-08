/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int moneyLost(int left, int right, vector<vector<int>> &dp) {
        
        // reached the guessed number
        // it will not contribute its value to result
        // so return 0
        if(left >= right) return 0;

        // already computed
        if(dp[left][right] != -1) return dp[left][right];

        // i => root
        // get MAX money lost (i.e., worst case) from both left and right branches of tree
        // calculate the total money lost for this specific root i which is = i + max(leftMoney, rightMoney)
        // do this for all possible roots in range [left, right]
        // final ans is the minimum value of worst case for any one of the possible roots 
        int ans = INT_MAX;
        for(int i=left; i<=right; i++) {
            int leftMoneyLost = moneyLost(left, i-1, dp);
            int rightMoneyLost = moneyLost(i+1, right, dp);
            int totalMoneyLost = i + max(leftMoneyLost, rightMoneyLost);
            ans = min(ans, totalMoneyLost);
        }

        return dp[left][right] = ans;
    }

public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return moneyLost(1, n, dp);
    }
};
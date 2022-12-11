/*******************************************************************
[6,7,3,1,7,2,8]
[3,6,4,7,2,5]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int getMaxElementOfSubarray(int i, int j, vector<int>& arr) {
        int maxElement = arr[i];
        for(int k=i; k<=j; k++) {
            maxElement = max(maxElement, arr[k]);
        }
        return maxElement;
    }

    int minimumCost(int i, int j, vector<int>& arr, vector<vector<int>> &dp) {

        if(i >= j) return 0;

        // 2 elements
        if(i + 1 == j) {
            return dp[i][j] = arr[i] * arr[j];
        }

        if(dp[i][j] != -1) return dp[i][j];

        // more than 2 elements
        int ans = INT_MAX;
        for(int k=i; k<j; k++) {

            int remainingCost = minimumCost(i, k, arr, dp) + minimumCost(k+1, j, arr, dp);
            
            int maxLeafLeft = getMaxElementOfSubarray(i, k, arr); // [i, k]
            int maxLeafRight = getMaxElementOfSubarray(k+1, j, arr); // [k+1, j]
            
            int totalCost = (maxLeafLeft * maxLeafRight) + remainingCost;
            ans = min(ans, totalCost);
        }

        return dp[i][j] = ans;
    }

public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));
        return minimumCost(0, arr.size()-1, arr, dp);
    }
};
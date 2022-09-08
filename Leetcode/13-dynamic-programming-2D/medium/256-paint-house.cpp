/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

// ************ TOP-DOWN ************
class Solution {

    int minimumCost(int i, int colour, vector<vector<int>> &costs, vector<vector<int>> &dp) {

        if(i == costs.size()) return 0;

        if(dp[i][colour] != -1) return dp[i][colour];

        int ans = INT_MAX;
        for(int nextColour=0; nextColour<3; nextColour++) {
            if(nextColour != colour) {
                int remainingCost = minimumCost(i+1, nextColour, costs, dp);
                ans = min(ans, costs[i][colour] + remainingCost);
            }
        }
        return dp[i][colour] = ans;
    }

public:
    int minCost(vector<vector<int>> &costs) {
        vector<vector<int>> dp(costs.size(), vector<int>(3, -1));
        int ans = INT_MAX;
        for(int colour=0; colour<3; colour++) {
            int cost = minimumCost(0, colour, costs, dp);
            ans = min(ans, cost);
        }
        return ans;
    }
};

// ************ BOTTOM-UP ************
class Solution {
public:
    int minCost(vector<vector<int>> &costs) {
        int n = costs.size();
        vector<int> dp(3, 0);

        for(int i=0; i<n; i++) {
            int colour0_cost = costs[i][0] + min(dp[1], dp[2]);
            int colour1_cost = costs[i][1] + min(dp[0], dp[2]);
            int colour2_cost = costs[i][2] + min(dp[0], dp[1]);

            dp[0] = colour0_cost;
            dp[1] = colour1_cost;
            dp[2] = colour2_cost;
        }

        return min(dp[0], min(dp[1], dp[2]));
        
    }
};
/*******************************************************************
DO BOTTOM UP DP TOO
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* WITH SORTING, MAP AS DP TOP-DOWN *************
class Solution {

    int minimumCost(int i, int j, vector<int> &cuts, map<pair<int, int>, int> &dp) {
        if(i >= j) return INT_MAX;

        if(dp.find({i, j}) != dp.end()) return dp[{i, j}];

        int minCost = INT_MAX;
        for(int cut=i+1; cut<j; cut++) {

            int leftCut = minimumCost(i, cut, cuts, dp);
            if(leftCut == INT_MAX) leftCut = 0; 

            int rightCut = minimumCost(cut, j, cuts, dp);
            if(rightCut == INT_MAX) rightCut = 0;

            int cost = (cuts[j] - cuts[i]) + leftCut + rightCut; 

            minCost = min(minCost, cost);
        }

        return dp[{i, j}] = minCost;
    }

public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        map<pair<int, int>, int> dp;
        return minimumCost(0, cuts.size()-1, cuts, dp);
    }
};

// ************* MAP AS DP TOP-DOWN *************
class Solution {

    int minimumCost(int i, int j, vector<int> &cuts, map<pair<int, int>, int> &dp) {
        if(i >= j) return INT_MAX;

        if(dp.find({i, j}) != dp.end()) return dp[{i, j}];

        int minCost = INT_MAX;
        for(int cut : cuts) {
            if(cut <= i || cut >= j) continue;

            int leftCut = minimumCost(i, cut, cuts, dp);
            if(leftCut == INT_MAX) leftCut = 0; 

            int rightCut = minimumCost(cut, j, cuts, dp);
            if(rightCut == INT_MAX) rightCut = 0;

            int cost = (j - i) + leftCut + rightCut; 

            minCost = min(minCost, cost);
        }

        return dp[{i, j}] = minCost;
    }

public:
    int minCost(int n, vector<int>& cuts) {

        map<pair<int, int>, int> dp;
        return minimumCost(0, n, cuts, dp);
    }
};


// ************* ALSO CORRECT BUT SHOWS MEMORY LIMIT EXCEEDED *************
class Solution {

    int minimumCost(int i, int j, vector<int> &cuts, vector<vector<int>> &dp) {
        if(i >= j) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];

        int minCost = INT_MAX;
        for(int cut : cuts) {
            if(cut <= i || cut >= j) continue;

            int leftCut = minimumCost(i, cut, cuts, dp);
            if(leftCut == INT_MAX) leftCut = 0; 

            int rightCut = minimumCost(cut, j, cuts, dp);
            if(rightCut == INT_MAX) rightCut = 0;

            int cost = (j - i) + leftCut + rightCut; 

            minCost = min(minCost, cost);
        }

        return dp[i][j] = minCost;
    }

public:
    int minCost(int n, vector<int>& cuts) {

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return minimumCost(0, n, cuts, dp);
    }
};
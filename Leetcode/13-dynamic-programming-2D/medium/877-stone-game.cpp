/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int alice_points(int i, int j, vector<int> stones, vector<vector<int>> &dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        // when even => alice makes a choice, otherwise
        // bob makes a choice so we don't include that
        // stones[i] in our answer
        bool even = (j - i) % 2 == 0 ? true : false;
        int left = 0;
        int right = 0;
        if(even) {
            left = stones[i];
            right = stones[j];
        }

        int pick_left = left + alice_points(i+1, j, stones, dp);
        int pick_right = right + alice_points(i, j-1, stones, dp);

        return dp[i][j] = max(pick_left, pick_right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        int total = accumulate(piles.begin(), piles.end(), 0);
        int alice = alice_points(0, n - 1, piles, dp);
        int bob = total - alice;

        return alice > bob;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int pick_max(int left, int right, vector<int> &nums, vector<vector<int>> &dp) {

    if(left == right || left + 1 == right) {
        return max(nums[left], nums[right]);
    }

    if(dp[left][right] != -1) return dp[left][right];

    // PLAYER - 1 PICKS LEFT
    // (player 2 can pick either left or right)
    // we have to minimize player 2's answer
    int player_2_picks_left = pick_max(left+2, right, nums, dp);
    int player_2_picks_right = pick_max(left+1, right-1, nums, dp);
    int player_1_picks_left = nums[left] + min(player_2_picks_left, player_2_picks_right);

    // PLAYER - 1 PICKS RIGHT
    // (player 2 can pick either left or right)
    // we have to minimize player 2's answer
    player_2_picks_left = pick_max(left+1, right-1, nums, dp);
    player_2_picks_right = pick_max(left, right-2, nums, dp);
    int player_1_picks_right = nums[right] + min(player_2_picks_left, player_2_picks_right);

    return dp[left][right] = max(player_1_picks_left, player_1_picks_right);
}


bool PredictTheWinner(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));

    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int player_1_score = pick_max(0, n-1, nums, dp);
    int player_2_score = total_sum - player_1_score;

    // cout<<"\nplayer 1 = "<<player_1_score<<", player 2 = "<<player_2_score;
    return player_1_score >= player_2_score;
}

int main() {

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ---------------- TOP-DOWN APPROACH ----------------
int rob_house(int i, vector<int>& nums, vector<int> &dp) {
    int n = nums.size();
    if(i >= n) return 0;
    if(dp[i] != -1) return dp[i];

    int include_curr_house = nums[i] + rob_house(i+2, nums, dp);
    int exclude_curr_house = i+1 < n ? rob_house(i+1, nums, dp) : 0;

    int max_profit = max(include_curr_house, exclude_curr_house);

    return dp[i] = max_profit;
}

int rob(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);

    int ans = rob_house(0, nums, dp);
    return ans;
}

// ---------------- BOTTOM-UP APPROACH ----------------
int rob(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);

    for(int i=n-1; i>=0; i--) {
        int include_curr_house = nums[i] + (i+2 < n ? dp[i+2] : 0);
        int exclude_curr_house = i+1 < n ? dp[i+1] : 0;
        dp[i] = max(include_curr_house, exclude_curr_house); 
    }

    return dp[0];
}

// ---------------- BOTTOM-UP APPROACH ----------------
int rob(vector<int>& nums) {
    int n = nums.size();

    for(int i=n-1; i>=0; i--) {
        int include_curr_house = nums[i] + (i+2 < n ? nums[i+2] : 0);
        int exclude_curr_house = i+1 < n ? nums[i+1] : 0;
        nums[i] = max(include_curr_house, exclude_curr_house); 
    }

    return nums[0];
}


int main() {

    return 0;
}
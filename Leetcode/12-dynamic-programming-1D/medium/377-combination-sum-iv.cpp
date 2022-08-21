/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// -------------- TOP-DOWN APPROACH --------------
int totalCombnations(int target, vector<int>& nums, vector<int> &dp) {
    if(target == 0) return 1;

    if(dp[target] != -1) return dp[target];

    int ctr = 0;
    for(int num : nums) {
        if(target - num >= 0) {
            ctr += totalCombnations(target-num, nums, dp);
        }
    }

    return dp[target] = ctr;
}

int combinationSum4(vector<int>& nums, int target) {
    vector<int> dp(target+1, -1);
    return totalCombnations(target, nums, dp);
}

// -------------- BOTTOM-UP APPROACH --------------
int combinationSum4(vector<int>& nums, int target) {
    vector<unsigned int> dp(target+1, 0);
    dp[0] = 1;

    for(int i=1; i<=target; i++) {
        for(int num : nums) {
            if(i - num >= 0) {
                dp[i] += dp[i-num];
            }
        }
    }

    return dp[target];
}
 
int main() {

    return 0;
}
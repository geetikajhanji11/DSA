/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool backtrack(int i, int subset_sum, int k, int &target, vector<int>& nums, vector<bool> &visited, map<vector<bool>, bool> &dp) {
    if(k == 0) return true;

    if(dp.find(visited) != dp.end()) return dp[visited];

    if(subset_sum == target) {
        return dp[visited] = backtrack(0, 0, k-1, target, nums, visited, dp);
    }

    for(int j=i; j<nums.size(); j++) {
        if(visited[j] || subset_sum + nums[j] > target) continue;
        visited[j] = true;
        if(backtrack(j+1, subset_sum + nums[j], k, target, nums, visited, dp)) return true;
        visited[j] = false;
    }

    return dp[visited] = false;
}

bool canPartitionKSubsets(vector<int>& nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % k != 0) return false;

    sort(nums.begin(), nums.end());
    
    int target = sum / k;
    vector<bool> visited(nums.size(), false);

    map<vector<bool>, bool> dp;

    return backtrack(0, 0, k, target, nums, visited, dp);
}

int main() {

    vector<int> nums = {4,3,2,3,5,2,1};
    int k = 4;

    canPartitionKSubsets(nums, k);
    return 0;
}
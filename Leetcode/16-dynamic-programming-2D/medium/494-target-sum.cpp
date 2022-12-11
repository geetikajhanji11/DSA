/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int all_ways(int i, int sum, int target, vector<int>& nums, map<pair<int,int>, int> &dp) {

    int n = nums.size();
    if(i == n) {
        if(sum == target) return 1;
        else return 0;
    }

    if(dp.find({i, sum}) != dp.end()) return dp.find({i, sum})->second;

    int adding_ways = all_ways(i+1, sum+nums[i], target, nums, dp);
    int subtract_ways = all_ways(i+1, sum-nums[i], target, nums, dp);

    dp.insert_or_assign({i, sum}, adding_ways + subtract_ways);
    return adding_ways + subtract_ways;
    
}

int findTargetSumWays(vector<int>& nums, int target) {
    map<pair<int,int>, int> dp;
    return all_ways(0, 0, target, nums, dp);
}

int main() {

    vector<int> nums = {1};
    int target = 1;

    cout<<findTargetSumWays(nums, target);
    
    return 0;
}
/*******************************************************************
Given non-empty, non-negative integer array nums, find if:
Can be partitionined into 2 subsets such that sums are equal
Ex. nums = [1,5,11,5] -> true, [1,5,5] & [11], both add to 11

Maintain DP set, for each num, check if num in set + curr = target
If not, add curr to every num in set we checked & iterate

Time: O(n x sum(nums))
Space: O(sum(nums))
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if(sum % 2 == 1) return false;

    int target = sum / 2;
    unordered_set<int> dp;
    dp.insert(0);

    for(int i=nums.size()-1; i>=0; i--) {
        unordered_set<int> new_dp;
        for(auto it=dp.begin(); it!=dp.end(); it++) {
            int num = *it;
            if(num + nums[i] == target) return true;
            new_dp.insert(num);
            new_dp.insert(num + nums[i]);
        }
        dp = new_dp;
    } 
    return false;
}

int main() {

    return 0;
}
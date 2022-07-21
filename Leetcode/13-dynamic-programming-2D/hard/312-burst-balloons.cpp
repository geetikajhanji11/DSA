/*******************************************************************
Given array of balloons w/ coins, if burst ith, get (i-1) + i + (i+1) coins
Return max coins can collect by bursting the balloons wisely

DP to return max coins obtainable in each interval [left, right]
Divide & conquer left & right depends on previous bursts, so think backwards
Instead of which one to burst first, need to think which one to burst last

Time: O(n^3) -> O(n^2) states, for each states, determining max coins is O(n)
Space: O(n^2) -> O(n^2) to store all states

// BOTTOM-UP
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // add 1 before & after nums
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        int n = nums.size();
        
        // cache results of dp
        vector<vector<int>> memo(n, vector<int>(n, 0));
        
        // 1 & n - 2 since we can't burst our fake balloons
        return dp(nums, memo, 1, n - 2);
    }
private:
    int dp(vector<int>& nums, vector<vector<int>>& memo, int left, int right) {
        // base case interval is empty, yields 0 coins
        if (right - left < 0) {
            return 0;
        }
        
        // we've already seen this, return from cache
        if (memo[left][right] > 0) {
            return memo[left][right];
        }
        
        // find the last burst in nums[left]...nums[right]
        int result = 0;
        for (int i = left; i <= right; i++) {
            // nums[i] is the last burst
            int curr = nums[left - 1] * nums[i] * nums[right + 1];
            // nums[i] is fixed, recursively call left & right sides
            int remaining = dp(nums, memo, left, i - 1) + dp(nums, memo, i + 1, right);
            result = max(result, curr + remaining);
        }
        // add to cache
        memo[left][right] = result;
        return result;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int dfs(int left, int right, vector<int>& nums, vector<vector<int>> &dp) {
    if(left > right) return 0;

    if(dp[left][right] != -1) return dp[left][right];

    // assuming ith balloon is the last balloon that we are popping
    for(int i=left; i<=right; i++) {
        int product = nums[left - 1] * nums[i] * nums[right + 1];
        int left_subarray_coins = dfs(left, i-1, nums, dp);
        int right_subarray_coins = dfs(i+1, right, nums, dp);

        int coins = left_subarray_coins + product + right_subarray_coins;

        dp[left][right] = max(dp[left][right], coins);
    }

    return dp[left][right];

}

int maxCoins(vector<int>& nums) {
    nums.push_back(1);
    nums.insert(nums.begin() + 0, 1);

    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));

    return dfs(1, nums.size()-2, nums, dp);
}

int main() {

    return 0;
}
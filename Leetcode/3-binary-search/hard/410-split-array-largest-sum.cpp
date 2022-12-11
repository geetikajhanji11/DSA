/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ******************* GREEDY & BINARY SEARCH *******************
class Solution {

    // greedy
    int canSplit(vector<int>& nums, int &maxSubarraySum, int &m) {
        int subarrayCount = 0;
        int subarraySum = 0;

        for(int num : nums) {
            subarraySum += num;
            if(subarraySum > maxSubarraySum) {
                subarrayCount++;
                subarraySum = num;
            }
        }

        return subarrayCount + 1 <= m;
    }

public:

    // binary search
    int splitArray(vector<int>& nums, int m) {
        
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);

        int result = INT_MAX;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(canSplit(nums, mid, m)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};


// ******************* DP - SOLUTION TLE *******************
class Solution {

    int minLargestSum(int i, int j, int totalSum, vector<int>& nums, int splits, vector<vector<vector<int>>> &dp) {
        if(i > j) return 0;
        if(i == j) return nums[i];

        if(dp[i][j][splits] != -1) return dp[i][j][splits];

        int leftHalfSum = 0;
        int rightHalfSum = 0;

        int answer = INT_MAX;
        for(int k=i; k<j; k++) {

            leftHalfSum += nums[k]; // [i,k]
            rightHalfSum = totalSum - leftHalfSum; // [k+1,j]
            
            if(splits > 1) {
                if(leftHalfSum < rightHalfSum) {
                    // dfs call on right half 
                    int minimizedRightSum = minLargestSum(k+1, j, rightHalfSum, nums, splits-1, dp);
                    answer = min(answer, max(leftHalfSum, minimizedRightSum));
                } else {
                    // dfs call on left half
                    int minimizedLeftSum = minLargestSum(i, k, leftHalfSum, nums, splits-1, dp);
                    answer = min(answer, max(rightHalfSum, minimizedLeftSum));
                }
            } else {
                answer = min(answer, max(leftHalfSum, rightHalfSum));
            }

        }

        return dp[i][j][splits] = answer;
    }

public:
    int splitArray(vector<int>& nums, int m) {
        int splits = m - 1;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // [i, splits] => ans
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(nums.size(), vector<int>(m, -1)));

        if(splits == 0) return totalSum;

        return minLargestSum(0, nums.size()-1, totalSum, nums, splits, dp);
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ***************** TOP - DOWN APPROACH *****************
class Solution {
public:

    long long maximumSum(int i, bool isIndexEven, vector<int>& nums, vector<vector<long long>> &dp) {

        if(i == nums.size()) return 0;

        if(dp[i][isIndexEven] != -1) return dp[i][isIndexEven];

        long long include;
        long long exclude;

        if(isIndexEven) {
            include = nums[i] + maximumSum(i+1, false, nums, dp);
            exclude = maximumSum(i+1, isIndexEven, nums, dp);
        } else {
            include = -nums[i] + maximumSum(i+1, true, nums, dp);
            exclude = maximumSum(i+1, isIndexEven, nums, dp);
        }    

        return dp[i][isIndexEven] = max(include, exclude);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        // n rows, 2 cols (2 for true[1]/false[0])
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));

        long long ans = maximumSum(0, true, nums, dp);

        return ans; 
    }
};

// ***************** BOTTOM - UP APPROACH *****************
class Solution {
public:

    long long maxAlternatingSum(vector<int>& nums) {
        long long sumEven = 0;
        long long sumOdd = 0;

        for(int i=nums.size()-1; i>=0; i--) {
            long long tempEven = max(sumOdd + nums[i], sumEven);
            long long tempOdd = max(sumEven - nums[i], sumOdd);
            sumEven = tempEven;
            sumOdd = tempOdd;
        }

        return sumEven;
    }
};

// ***************** RECURSIVE *****************
class Solution {
public:

    // handle -1 case for lastIndex
    long long maximumSum(int i, int lastIndex, long long evenSum, long long oddSum, vector<int>& nums) {

        if(i == nums.size() && lastIndex == -1) return 0;

        if(i == nums.size()) return evenSum - oddSum;

        // exclude current number
        long long op2 = maximumSum(i+1, lastIndex, evenSum, oddSum, nums);

        // include current number
        if(lastIndex % 2 == 0) {
            oddSum += nums[i]; // lastIndex = even, currIndex = odd
        } else {
            evenSum += nums[i]; // lastIndex = odd, currIndex = even
        }
        long long op1 = maximumSum(i+1, lastIndex+1, evenSum, oddSum, nums);

        return max(op1, op2);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        return maximumSum(0, -1, 0, 0, nums);
    }
};

int main() {

    return 0;
}
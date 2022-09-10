/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        
        int array_sum = accumulate(nums.begin(), nums.end(), 0);

        // for maximum subarray sum
        int max_straight_sum = INT_MIN;
        int temp_max_sum = 0;

        // for minimum subarray sum
        int min_straight_sum = INT_MAX;
        int temp_min_sum = 0;

        // kadane's algorithm
        for(int num : nums) {

            // for maximum subarray sum
            temp_max_sum += num;
            max_straight_sum = max(max_straight_sum, temp_max_sum);
            if(temp_max_sum < 0) {
                temp_max_sum = 0;
            }

            // for minimum subarray sum
            temp_min_sum += num;
            min_straight_sum = min(min_straight_sum, temp_min_sum);
            if(temp_min_sum > 0) {
                temp_min_sum = 0;
            }
        }

        if(array_sum == min_straight_sum) {
            return max_straight_sum;
        }

        return max(max_straight_sum, array_sum - min_straight_sum);

    }
};
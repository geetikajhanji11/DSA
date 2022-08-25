/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int left = 0;
        int right = 0;

        int minDiff = INT_MAX;

        while(right < nums.size()) {
            if(right - left + 1 == k) {
                minDiff = min(minDiff, nums[right] - nums[left]);
                left++;
            }   
            right++;
        }    

        return minDiff;
    }
};
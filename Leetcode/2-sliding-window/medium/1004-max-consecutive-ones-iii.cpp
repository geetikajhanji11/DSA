/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;

        int maxLen = 0;
        int zeroes = 0;

        while(right < nums.size()) {
            
            if(nums[right] == 0) zeroes++;
            
            // contract window if number of zeroes > k
            while(zeroes > k) {
                if(nums[left] == 0) zeroes--;
                left++;
            }

            maxLen = max(maxLen, right - left + 1);
            
            right++;
        }

        return maxLen;
    }
};
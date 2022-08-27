/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        
        int minLen = INT_MAX;

        int left = 0;
        int right = 0;

        int subarraySum = 0;

        while(right < nums.size()) {
            subarraySum += nums[right];

            while(subarraySum >= target) {
                minLen = min(minLen, right - left + 1);
                subarraySum -= nums[left];
                left++;
            }

            right++;
        }

        if(minLen == INT_MAX) return 0;
        return minLen;

    }
};
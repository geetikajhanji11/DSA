/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isValid(vector<int>& nums, int maxBalls, int &maxOperations) {
        int operations = 0;

        for(int balls : nums) {
            if(balls <= maxBalls) continue;
            operations += (balls - 1) / maxBalls;
        }

        return operations <= maxOperations;
    }

public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());

        int ans = 0;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(isValid(nums, mid, maxOperations)) {
                high = mid - 1;
                ans = mid;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
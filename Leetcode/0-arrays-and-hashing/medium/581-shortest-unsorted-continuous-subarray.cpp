/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isOutOfOrder(vector<int>& nums, int &i) {

        if(i == 0) {
            if(i + 1 < nums.size()) {
                return nums[i] > nums[i+1];
            }
            return false;
        }

        if(i == nums.size() - 1) {
            return nums[i-1] > nums[i];
        } 

        return (nums[i-1] > nums[i] || nums[i] > nums[i+1]);
    }

public:
    int findUnsortedSubarray(vector<int>& nums) {

        int smallest = INT_MAX;
        int biggest = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            if(isOutOfOrder(nums, i)) {
                if(nums[i] < smallest) {
                    smallest = nums[i];
                }
                if(nums[i] > biggest) {
                    biggest = nums[i];
                }
            }
        }

        if(smallest == INT_MAX) return 0;

        int i = 0;
        while(i < nums.size() && nums[i] <= smallest) i++;

        int j = nums.size() - 1;
        while(j >= 0 && nums[j] >= biggest) j--;

        return j - i + 1;

    }
};
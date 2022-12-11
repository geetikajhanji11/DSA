/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int midLeft = (mid - 1) >= 0 ? nums[mid-1] : INT_MIN;
            int midRight = (mid + 1) < nums.size() ? nums[mid+1] : INT_MIN;
        
            if(nums[mid] > midLeft && nums[mid] > midRight) return mid;
            else if(midLeft > nums[mid]) high = mid - 1;
            else low = mid + 1;
        }

        return high;
    }
};
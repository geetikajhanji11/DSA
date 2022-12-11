/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        
        int n = nums.size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {

            // handles duplicates and reduces search space
            while(low < high && nums[low] == nums[low + 1]) low++;
            while(low < high && nums[high] == nums[high - 1]) high--;

            // get the middle index
            int mid = (low + high) / 2;

            // found the target 
            if(nums[mid] == target) return true;

            // left side is sorted
            else if(nums[low] <= nums[mid]) {

                // and target exists inside this interval
                // go left
                if(nums[low] <= target && target <= nums[mid]) {
                    high = mid - 1;
                } 
                
                // go right
                else {
                    low = mid + 1;
                }   
            } 
            
            // right side is sorted
            else {

                // and target exists inside this interval
                // go right
                if(nums[mid] <= target && target <= nums[high]) {
                    low = mid + 1;
                } 
                
                // go left
                else {
                    high = mid - 1;
                } 
            }
        }

        return false;
    }
};
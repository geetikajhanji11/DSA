/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        
        bool changed = false;

        for(int i=0; i<nums.size() - 1; i++) {
            
            if(nums[i] <= nums[i+1]) continue;
            if(changed) return false;

            // ------ PERFORMING A CHANGE ------
            changed = true;

            // modify either the ith element to smaller value (i+1)
            // [i-1, i, i+1]
            // [ 1,  4,  2 ] 
            // i == 0 handles edge case [4, 2]
            if(i == 0 || nums[i-1] <= nums[i+1]) {
                nums[i] = nums[i+1];
            }
            // or modify the (i+1)th element to larger value (ith) 
            // [i-1, i, i+1]
            // [ 3,  4,  2 ] 
            else {
                nums[i+1] = nums[i];
            }
            
        }

        return true;
    }
};
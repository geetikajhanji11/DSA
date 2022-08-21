/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstMissingPositive(vector<int>& nums) {

    // change all the -ve values to 0
    for(int i=0; i<nums.size(); i++) {
        if(nums[i] < 0) {
            nums[i] = 0;
        }
    }        

    // make values negative such that the sign of 
    // the ith value indicates that (i+1) exists in array
    for(int i=0; i<nums.size(); i++) {

        int targetIdx = abs(nums[i]) - 1;

        // out of bounds
        if(targetIdx < 0 || targetIdx >= nums.size()) continue;

        if(nums[targetIdx] > 0) {
            nums[targetIdx] *= -1;
        } 
        
        // in case of 0: default value = -(len(nums) + 1)
        else if(nums[targetIdx] == 0) {
            nums[targetIdx] = -1 * (nums.size() + 1);
        } 
    }

    // solution set is [1 ... (len(nums)+1)]
    for(int ans=1; ans<=nums.size(); ans++) {
        int idx = ans - 1;
        if(nums[idx] >= 0) return ans;
    }

    return nums.size() + 1;
}

int main() {

    return 0;
}
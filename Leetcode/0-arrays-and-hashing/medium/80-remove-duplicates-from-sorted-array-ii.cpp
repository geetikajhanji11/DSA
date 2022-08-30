/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.size() <= 2) return nums.size();
        
        int i = 0;
        int j = 0;

        int currNum = nums[0];
        int ctr = 0;
        
        while(j < nums.size()) {

            while(j < nums.size() && nums[j] == currNum) {
                j++;
                ctr++;
            }

            if(ctr >= 2) {
                nums[i] = currNum;
                nums[i+1] = currNum;
                i = i + 2;
            } else {
                nums[i] = currNum;
                i = i + 1;
            }

            currNum = nums[j];
            ctr = 0;
        }

        return i;
    }
};
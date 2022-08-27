/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// LESS OPERATIONS
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        for(int right=0; right<nums.size(); right++) {
            if(nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};

// MORE OPERATIONS
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int ctr = 0;
        int index = 0;
        
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                ctr++;
                continue;
            }
            nums[index] = nums[i];
            index++;
        }
        
        index = nums.size()-1;
        while(ctr != 0) {
            nums[index] = 0;
            ctr--;
            index--;
        }
    }
};
/*******************************************************************
[4,6,3,2,1,5,3]
[3,2,2]
[2,2]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(n) time
// O(1) space
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {

        int total_xor = 0;
        int array_xor = 0;

        for(int i=1; i<=nums.size(); i++) {
            total_xor = total_xor ^ i;
        }

        for(int i=0; i<nums.size(); i++) {

            array_xor = array_xor ^ abs(nums[i]);
            
            if(nums[i] < 0) continue;

            int nextIdx = nums[i] - 1; 

            while(nums[nextIdx] >= 0) { 
                int val = nums[nextIdx]; 
                nums[nextIdx] = -val;
                nextIdx = val - 1; 
            }
        }

        int repeat_xor_missing = array_xor ^ total_xor;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i] >= 0) {
                // missing number is = i+1
                int missing = i + 1;
                int repeat = repeat_xor_missing ^ missing;
                return {repeat, missing};
            }
        }

        return {};
    }
};
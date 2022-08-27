/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int maxLength = 1;
        int currLength = 1;

        for(int i=1; i<nums.size(); i++) {
            
            if(nums[i-1] < nums[i]) {
                currLength++;
                maxLength = max(maxLength, currLength);
            } else {
                currLength = 1;
            }
        }
        return maxLength;
    }
};
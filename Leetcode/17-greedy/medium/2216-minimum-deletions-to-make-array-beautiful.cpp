/*******************************************************************
[4,4,4,4,6,6,6,6,6,6,6,8]
[1,1,2,3,3,4,5,5]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDeletion(vector<int>& nums) {

        if(nums.size() == 0) return 0;
        
        int prevIndex = 0;
        int prevNum = nums[0];
        
        int dels = 0;

        for(int i=1; i<nums.size(); i++) {
            int currIndex = i;
            int currNum = nums[i];

            // this condition makes array NOT beautiful
            // hence we need to perform a deletion
            if(prevNum == currNum && prevIndex % 2 == 0) {
                // prevIndex does not change
                dels++;
            } else {
                prevIndex++;
                prevNum = currNum;
            }
        }

        // prevIndex points to the last index
        // of the new beautiful array
        // prevIndex = odd => total elements are even
        // prevIndex = even => total elements are odd
        if(prevIndex % 2 == 0) return dels + 1;
        return dels;
    }
};
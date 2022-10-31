/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isCloser(int &currSum, int &closestSum, int &target) {
        return abs(currSum - target) <= abs(closestSum - target);
    }

public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int closestSum = INT_MAX - 100000;

        for(int i=0; i<nums.size(); i++) {
            int a = nums[i];
            
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {
                int currSum = a + nums[left] + nums[right];

                if(currSum == target) return target;

                if(isCloser(currSum, closestSum, target)) {
                    closestSum = currSum;
                }

                // currsum is smaller, make curr sum greater for closer
                if(currSum < target) left++;

                // currsum is greater, make curr sum smaller for closer
                else if(currSum > target) right--; 
                
            }
        }
        return closestSum;
    }
};
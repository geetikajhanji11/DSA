/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;

        for(int i=0; i<nums.size(); i++) {

            // handle duplicate
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;

            int twoSum = 0 - nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while(left < right) {

                // handle duplicate
                while(left < nums.size() && left-1 > i && nums[left] == nums[left-1]) left++;
                while(right > i && right+1 < nums.size() && nums[right] == nums[right+1]) right--;
                if(left >= right) break;

                int sum = nums[left] + nums[right];

                if(sum == twoSum) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    
                } else if(sum < twoSum) {
                    left++;
                } else {
                    right--;
                }
                
            }

        }

        return result;

    }
};
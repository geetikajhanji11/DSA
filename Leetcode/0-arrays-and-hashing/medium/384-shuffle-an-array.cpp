/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nums;

public:
    Solution(vector<int>& nums) {
        this->nums = nums;
    }
    
    vector<int> reset() {
        return nums;
    }
    
    vector<int> shuffle() {

        vector<int> result = nums;

        for(int i=0; i<nums.size(); i++) {
            int j = rand() % nums.size();
            swap(result[i], result[j]);
        }

        return result;

    }
};
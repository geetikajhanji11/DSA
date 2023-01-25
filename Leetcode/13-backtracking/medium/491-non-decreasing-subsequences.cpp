/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void subsequence(int i, vector<int> curr, vector<int>& nums, set<vector<int>> &result) {
        if(i == nums.size()) {
            if(curr.size() > 1) result.insert(curr);
            return;
        }

        // don't insert
        subsequence(i+1, curr, nums, result);

        // insert only on condition
        if(curr.size() == 0 || curr.back() <= nums[i]) {
            curr.push_back(nums[i]);
            subsequence(i+1, curr, nums, result);
        }
    }

public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        subsequence(0, {}, nums, s);

        vector<vector<int>> result(s.begin(), s.end());

        return result;
    }
};
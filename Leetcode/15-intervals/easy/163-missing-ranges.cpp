/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void addString(int left, int right, vector<string> &result) {
        string str = to_string(left);
        if(left != right) {
            str += "->";
            str += to_string(right);
        }
        result.push_back(str);
    }

public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        vector<string> result;

        if(n == 0) {
            addString(lower, upper, result);
            return result;
        }

        int curr = min(lower, nums[0]);
        for(int i=0; i<n; i++) {
            if(i-1 >= 0 && nums[i] == nums[i-1]) continue;
            if(curr != nums[i]) {
                int left = (i-1 < 0 ? lower : nums[i-1] + 1);
                int right = nums[i] - 1;
                addString(left, right, result);

                curr = nums[i] + 1;
            } else {
                curr++;
            }
        }

        if(nums[n-1] < upper) {
            int left = nums[n-1] + 1;
            int right = upper;
            addString(left, right, result);
        }

        return result;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seenRemainders;
        seenRemainders.insert({0, -1});

        int prefixSum = 0;
        for(int i=0; i<nums.size(); i++) {
            prefixSum += nums[i];

            int rem = prefixSum % k;

            if(seenRemainders.find(rem) == seenRemainders.end()) {
                seenRemainders[rem] = i;
            } else {
                if(i - seenRemainders[rem] > 1) return true;
            }
        }

        return false;
    }
};
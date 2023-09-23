/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {

        int sum = 0;
        unordered_map<int, int> seen; // sum => first encountered index for sum
        seen[0] = -1;
        int largestLength = 0;

        for(int i=0; i<nums.size(); i++) {
            sum += (nums[i] == 1 ? 1 : -1);
            if(seen.find(sum) == seen.end()) {
                seen[sum] = i;
            } else {
                largestLength = max(largestLength, i - seen[sum]);
            }
        }

        if(sum == 0) return nums.size();
        return largestLength;
    }
};
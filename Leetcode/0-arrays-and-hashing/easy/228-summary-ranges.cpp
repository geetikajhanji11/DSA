/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        
        vector<string> result;

        for(int i=0; i<nums.size(); i++) {
            string curr = "";

            int start = i;
            while(i+1 < nums.size() && nums[i+1] == nums[i] + 1) {
                i++;
            }
            int end = i;

            curr += to_string(nums[start]);
            if(start != end) {
                curr += "->" + to_string(nums[end]);
            } 

            result.push_back(curr);
        }

        return result;
    }
};
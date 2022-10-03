/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> s;
        int n = nums.size();

        vector<int> result(n);

        // populate the stack initially from end to start
        for(int i=n-1; i>=0; i--) {
            while(!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }
            s.push(nums[i]);
        }

        // apply "next-greater-element-i" logic
        // traverse array from end to start with
        // the newly populated stack
        for(int i=n-1; i>=0; i--) {

            while(!s.empty() && nums[i] >= s.top()) {
                s.pop();
            }

            // filling the result array
            if(!s.empty()) {
                result[i] = s.top();
            } else {
                result[i] = -1;
            }

            s.push(nums[i]);
        } 

        return result;
    }
};
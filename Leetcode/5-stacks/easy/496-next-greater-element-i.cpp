/*******************************************************************
MONOTONICALLY INCREASING STACK

TOP - SMALLER
-
-
BOTTOM - GREATER
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> s;
        unordered_map<int, int> numToAnswer;
        
        for(int i=nums2.size()-1; i>=0; i--) {
            
            int num = nums2[i];
            
            while(!s.empty() && s.top() < num) {
                s.pop();
            }

            if(s.empty()) numToAnswer[num] = -1;
            else numToAnswer[num] = s.top();

            s.push(num);
        }


        vector<int> result;
        for(int num : nums1) {
            result.push_back(numToAnswer[num]);
        } 
        
        return result;
    }
};
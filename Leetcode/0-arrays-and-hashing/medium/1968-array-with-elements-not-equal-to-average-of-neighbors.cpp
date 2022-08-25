/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** MY SOLUTION **************
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i=i+2) {
            swap(nums[i], nums[i-1]);
        }

        return nums;
    }
};

// ************** NEETCODE SOLUTION **************
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
    
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int> result(n, 0);

        int i = 0;

        // fill all even indexs with smaller number
        for(int j=0; j<n; j=j+2) {
            result[j] = nums[i];
            i++; 
        }

        // fill all odd indexes with larger number
        for(int j=1; j<n; j=j+2) {
            result[j] = nums[i];
            i++; 
        }
        
        return result;
    }
};
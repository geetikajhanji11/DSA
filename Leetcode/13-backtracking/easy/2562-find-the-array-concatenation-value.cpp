/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long getSum(vector<int>& nums, int i, int j) {
        long long sum = 0;

        if(i > j) return sum;

        else if(i == j) {
            sum += nums[i];
        } 
        
        else {
            string t = to_string(nums[i]) + to_string(nums[j]);
            sum += stoi(t);
        }

        return sum + getSum(nums, i+1, j-1);
    }

public:
    long long findTheArrayConcVal(vector<int>& nums) {
        int n = nums.size();
        return getSum(nums, 0, n-1);
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NumArray {

    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int num : nums) {
            sum += num;
            prefixSum.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return prefixSum[right];
        return prefixSum[right] - prefixSum[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
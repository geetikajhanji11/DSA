/*******************************************************************
 * https://www.youtube.com/watch?v=CWDQJGaN1gY&ab_channel=TusharRoy-CodingMadeSimple

This is a classic Dynamic Range Sum Query problem, 
to query sum in range efficiently where elements can be updated dynamically.

This problem can be solved in various approaches such as: Segment Tree, 
BIT, Sqrt Decomposition...
In this post, I use Binary Indexed Tree (BIT) structure 
because it's easy to implement and it has high performance.

In BIT structure, there are 2 basic operations:

    => addValue(idx, value)
            Add an amount of value into element 
            at index idx (1-based indexing), 
            time: O(logN)

    => getSum(idx):     
            Get sum in range [0..idx] (1-based indexing), 
            time: O(logN)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** BINARY INDEXED TREE SOLUTION ***************
class BIT { // One-based indexing
    vector<int> bit;
public:

    // initialize vector size
    BIT(int size=0) {
        bit.assign(size + 1, 0);
    }

    // Get sum in range [1..idx]
    int getSum(int idx) { 
        int sum = 0;
        while(idx > 0) {
            sum += bit[idx];

            int parentIdx = idx & (-idx);
            idx -= parentIdx;
        }
        return sum;
    }

    // update value
    void updateValue(int idx, int val) {

        while(idx < bit.size()) {
            bit[idx] += val;

            int childIdx = idx & (-idx);
            idx += childIdx;
        }
            
    }
};
class NumArray {
    BIT bit;
    vector<int> nums;
public:

    NumArray(vector<int>& nums) {
        this->bit = BIT(nums.size());
        this->nums = nums;
        for (int i = 0; i < nums.size(); ++i)
            bit.updateValue(i+1, nums[i]);
    }

    void update(int index, int val) {

        // get diff amount of `val` compared to current value
        int diff = val - nums[index]; 

        // add this `diff` amount at index `index+1` of BIT, 
        // plus 1 because in BIT it's 1-based indexing
        bit.updateValue(index+1, diff); 

        // update latest value of `nums[index]`
        nums[index] = val; 
    }

    int sumRange(int left, int right) {
        return bit.getSum(right+1) - bit.getSum(left);
    }
};

// *************** NAIVE SOLUTION ***************
class NumArray {

    vector<int> arr;
    vector<int> prefixSum;

public:
    NumArray(vector<int>& nums) {
        int sum = 0;
        for(int i=0; i<nums.size(); i++) {
            sum += nums[i];
            prefixSum.push_back(sum);
            arr.push_back(nums[i]);
        }
    }
    
    void update(int index, int val) {
        int diff = arr[index] - val;

        for(int i=index; i<arr.size(); i++) {
            prefixSum[i] -= diff;
        } 

        arr[index] = val;
    }   
    
    int sumRange(int left, int right) {
        if(left == right) return arr[left];
        return prefixSum[right] - (left-1 >= 0 ? prefixSum[left-1] : 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
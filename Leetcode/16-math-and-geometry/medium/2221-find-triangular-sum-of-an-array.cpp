/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********* O(N) *********
// runtime error due to large number
class Solution {
public:

    // the nth row of pascal's triangle is
    // the frequency of every digit at ith pos
    int triangularSum(vector<int>& nums) {
        int n = nums.size() - 1;
        int result = 0;
        int nCr = 1;

        for(int r=0; r<nums.size(); r++) {
            int num = nums[r];
            result = (result + nCr * num) % 10;
            nCr = nCr * (n - r) / (r + 1);
        }

        return result;
    }
};

// ********* O(N^2) *********
class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n = nums.size();

        while(n != 1) {
            for(int i=0; i<n-1; i++) {
                nums[i] = (nums[i] + nums[i+1]) % 10; 
            }
            n--;
        }

        return nums[0];
    }
};
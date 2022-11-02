/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        unordered_map<int, int> sumCount;
        int target = 0;

        for(int num1 : nums1) {
            for(int num2 : nums2) {
                sumCount[num1 + num2]++;
            }
        } 

        int count = 0;
        for(int num3 : nums3) {
            for(int num4 : nums4) {
                int remainingSum = target - (num3 + num4);
                count += sumCount[remainingSum];
            }
        }

        return count;
    }
};
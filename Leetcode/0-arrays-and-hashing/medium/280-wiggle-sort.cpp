/*******************************************************************
nums[0] <= nums[1] >= nums[2] <= nums[3]....
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* O(N) *************
class Solution {
public:
    void wiggleSort(vector<int> &nums) {

        for(int i=0; i<nums.size(); i++) {
            
            // index is even
            // SHOULD BE: nums[i-1] >= nums[i] 
            if(i % 2 == 0) {
                if(i-1 >= 0 && nums[i-1] < nums[i]) {
                    swap(nums[i], nums[i-1]);
                }
            } 
            
            // index is odd
            // SHOULD BE: nums[i-1] <= nums[i] 
            else {
                if(i-1 >= 0 && nums[i-1] > nums[i]) {
                    swap(nums[i], nums[i-1]);
                }
            }
        }
    }
};

// ************* MY SOLUTION (NLOGN) *************
class Solution {
public:
    void wiggleSort(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        for(int i=1; i<nums.size(); i=i+2) {
            if(i+1 < nums.size()) {
                swap(nums[i], nums[i+1]);
            }
        }
    }
};
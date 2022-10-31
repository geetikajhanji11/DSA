/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** DISCUSS SOLUTION ***********
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> squares(nums.size());
        int k = nums.size() - 1;

        int low = 0;
        int high = nums.size() - 1;

        while(k >= 0) {

            if(abs(nums[low]) > abs(nums[high])) {
                squares[k] = nums[low] * nums[low];
                low++;
            } else {
                squares[k] = nums[high] * nums[high];
                high--;
            }

            k--;
        }

        return squares;
    }
};

// *********** MY SOLUTION ***********
class Solution {

    // get the index of the first whole number in nums 
    int getFirstPositiveIndex(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int index = nums.size();
        while(low <= high) {
            int mid = (low + high) / 2;
            if(nums[mid] >= 0) {
                index = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return index;
    }

public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        vector<int> squares;

        int right = getFirstPositiveIndex(nums);
        int left = right - 1;

        while(squares.size() < nums.size()) {

            // both left and right are in bounds
            if(left >= 0 && right < nums.size()) {
                if(abs(nums[left]) < abs(nums[right])) {
                    squares.push_back(nums[left] * nums[left]);
                    left--;
                } else {
                    squares.push_back(nums[right] * nums[right]);
                    right++;
                }
            } 

            // only left is in bounds
            else if(left >= 0) {
                squares.push_back(nums[left] * nums[left]);
                left--;
            } 
            
            // only right is in bounds
            else if(right < nums.size()) {
                squares.push_back(nums[right] * nums[right]);
                right++;
            }

        }

        return squares;
    }
};
/*******************************************************************
Suppose array is [1, 1, 2, 2, 3, 3, 4, 5, 5]
we can observe that for each pair, 
first element takes even position and second element takes odd position
for example, 1 is appeared as a pair,
so it takes 0 and 1 positions. similarly for all the pairs also.

this pattern will be missed when single element is appeared in the array.

From these points, we can implement algorithm.
1. Take left and right pointers . 
    left points to start of list. right points to end of the list.
2. find mid.

3.  if mid is even, then it's duplicate should be in next index.
	or if mid is odd, then it's duplicate  should be in previous index.
	check these two conditions, 

[0,1,2,3,4,5,6,7,8] = index
[1,1,2,3,3,4,4,8,8] = array

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isAlone(int i, vector<int>& nums) {
        if(i - 1 >= 0 && nums[i - 1] == nums[i]) return false;
        if(i + 1 < nums.size() && nums[i + 1] == nums[i]) return false;
        return true;
    }

public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            // check left and right
            if(isAlone(mid, nums)) return nums[mid];


            // if mid is even
            // duplicate should be at right
            if(mid % 2 == 0) {

                // no more right 
                // go left
                if(mid + 1 == nums.size()) {
                    high = mid - 1;
                }

                // duplicate is at right
                // all okay at left side
                //go right
                else if(nums[mid + 1] == nums[mid]) {
                    low = mid + 1;
                } 
                
                // duplicate is not at right
                // something wrong on left
                // go left
                else {
                    high = mid - 1;
                }

            } 
            
            // if mid is odd
            // duplicate should be at left
            else {

                // no more left
                // go right
                if(mid - 1 < 0) {
                    low = mid + 1;
                }

                // duplicate is at left
                // all okay at left side
                // go right
                else if(nums[mid - 1] == nums[mid]) {
                    low = mid + 1;
                } 
                
                // duplicate is not at left
                // something wrong on left
                // go left
                else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
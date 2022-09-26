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
    if mid is even, then it's duplicate should be in next index.
	or if mid is odd, then it's duplicate  should be in previous index.
	check these two conditions, 
	if any of the conditions is satisfied,
	then pattern is not missed, 
	so check in next half of the array. i.e, left = mid + 1
	if condition is not satisfied, then the pattern is missed.
	so, single number must be before mid.
	so, update end to mid.
3. At last return the nums[left]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;
            int left = mid - 1;
            int right = mid + 1;

            if(left >= 0 && nums[mid] == nums[left]) {

                // go left
                if(mid % 2 == 0) high = mid - 1;

                // go right
                else low = mid + 1;
            } 
            
            else if(right < n && nums[mid] == nums[right]) {

                // go right
                if(mid % 2 == 0) low = mid + 1; 

                // go left
                else high = mid - 1;
            } 
            
            else {
                return nums[mid];
            }
        }

        return -1;
    }
};
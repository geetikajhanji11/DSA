/*******************************************************************
Given int array, determine min jumps to reach last index
Ex. nums = [2,3,1,1,4] -> 2, index 0 to 1 to last

Greedy: At each point, determine furthest reachable, jump to it

Time: O(n)
Space: O(1)

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int jump(vector<int>& nums) {
    int result = 0;
    int left = 0;
    int right = 0;

    // excluding the last element (since it is our goal)
    while(right < nums.size() - 1) { 
        int farthest_index = 0;
        for(int i=left; i<=right; i++) {
            farthest_index = max(farthest_index, i + nums[i]);
        }

        // setting the left and right of the next window
        left = right + 1;
        right = farthest_index;
        result++;
    }

    return result;
}

int main() {

    return 0;
}
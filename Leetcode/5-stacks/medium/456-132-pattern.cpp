/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// [num, min num left of array]
class Pair {
public:
    int num;
    int minLeft;
    Pair(int num, int minLeft) {
        this->num = num;
        this->minLeft = minLeft;
    }
};

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        
        // nums[i] < nums[k] < nums[j]

        // monotonically decreasing stack
        // nums[j] = top of the stack (which is max num)
        // nums[i] = minLeft  
        // nums[k] = current element being processed
        stack<Pair> s;

        int currMin = nums[0];

        for(int k=1; k<nums.size(); k++) {

            // while nums[k] > nums[j]... keep popping
            while(!s.empty() && nums[k] >= s.top().num) {
                s.pop();
            }

            // nums[i] < nums[k] < nums[j]
            if(!s.empty() && nums[k] < s.top().num && nums[k] > s.top().minLeft) {
                return true;
            }

            s.push(Pair(nums[k], currMin));
            currMin = min(currMin, nums[k]);

        }

        return false;
    }
};
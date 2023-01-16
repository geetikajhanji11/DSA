/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();

        vector<int> copy = nums;
        sort(copy.begin(), copy.end());

        int left = (n + 1) / 2 - 1; // median
        int right = n - 1;

        for(int i=0; i<n; i++) {
            
            // even index
            if(i % 2 == 0) {
                // copy values decremeting from median on even indexes
                nums[i] = copy[left];
                left--;
            } 
            
            // odd index
            else {
                // copy large values on odd indexes
                nums[i] = copy[right];
                right--;
            }
        }
    }
};


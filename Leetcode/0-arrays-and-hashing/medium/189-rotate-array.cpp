/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {

        int i, j;
        int n = nums.size();

        k = k % n;

        // reverse entire array
        reverse(nums.begin(), nums.end());

        // reverse [0, k-1]
        i = 0;
        j = k - 1;
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

        // reverse [k, n-1]
        i = k;
        j = n - 1;
        while(i < j) {
            swap(nums[i], nums[j]);
            i++;
            j--;
        }

    }
};
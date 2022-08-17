/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numSubseq(vector<int>& nums, int target) {

    int MOD = (int)1e9 + 7;
    int n = nums.size();

    sort(nums.begin(), nums.end());
    
    int result = 0;
    int right = n - 1;
    
    vector<int> power(n, 1);
    power[0] = 1;
    
    // pre computing all powers of 2 upto 2^n
    // since it creates a problem after
    for(int i=1; i<n ; i++) {
        power[i] = fmod(power[i-1]*2, MOD);
    }
    
    // going over the array
    for(int left=0; left<n; left++){

        while(right >= left && nums[left] + nums[right] > target) {
            right--;
        }
        
        if(left <= right) {
            result = fmod(result + power[right-left], MOD);
        }
    }
    
    return result;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int house_robber_1(vector<int>& nums) {
    int n = nums.size();
    for(int i=n-1; i>=0; i--) {
        int include_curr_house = nums[i] + (i+2 < n ? nums[i+2] : 0);
        int exclude_curr_house = i+1 < n ? nums[i+1] : 0;
        nums[i] = max(include_curr_house, exclude_curr_house); 
    }
    return nums[0];
}

int rob(vector<int>& nums) {
    vector<int> nums1 = nums;
    vector<int> nums2 = nums;

    nums1.pop_back(); // new array, just removed last element
    nums2.erase(nums2.begin()); // new array, just removed first element

    int ans1 = house_robber_1(nums1);
    int ans2 = house_robber_1(nums2);

    return max(ans1, ans2);
}

int main() {

    return 0;
}
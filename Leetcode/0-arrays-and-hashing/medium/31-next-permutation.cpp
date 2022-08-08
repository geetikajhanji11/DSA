/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    // find the first element from the 
    // end of array that is less that its next
    // element
    int left = n-2;
    while(left >= 0) {
        if(nums[left] < nums[left+1]) break;
        left--;
    }

    // if whole array is ascending order,
    // reverse it and return since no
    // next permutation is possible
    if(left == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }

    // if there is a next permutation possible
    // find the element from left side of array
    // which is greater than element at nums[left]
    int right = n-1;
    while(right > left) {
        if(nums[right] > nums[left]) break;
        right--;
    }

    swap(nums[left], nums[right]);
    // reverse rest of the elements from left+1
    reverse(nums.begin() + left + 1, nums.end());
}

int main() {

    // 1,2,4,3,5

    vector<int> v = {1,2,3,5,4};
    nextPermutation(v);
    cout<<"\nans\n";
    for(int num : v) {
        cout<<num<<", ";
    }
    return 0;
}
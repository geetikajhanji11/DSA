#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int search(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;

    int index = -1;

    // at any point in an iteration,
    // either left part will be sorted
    // or the right part
    while(low <= high) {
        int mid = (low + high) / 2;

        // we found the target
        if(nums[mid] == target) {
            index = mid;
            break;
        }

        // if left part is sorted
        if(nums[low] <= nums[mid]) {
            if(nums[low] <= target && target <= nums[mid]) { // target lies in range
                high = mid - 1;
            } else {    // go other side
                low = mid + 1;
            }
        }

        // if right part is sorted
        else if(nums[mid] <= nums[high]) {
            if(nums[mid] <= target && target <= nums[high]) { // target lies in range
                low = mid + 1;
            } else {    // go other side
                high = mid - 1;
            }
        } 
    }

    return index;
}

int main() {

    vector<int> nums = {4,5,6,7,0,1,2};
    int ans = search(nums, 3);
    cout<<ans;
    return 0;
}
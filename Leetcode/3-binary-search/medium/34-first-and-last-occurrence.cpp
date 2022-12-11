#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    
    // search left 
    // (first occurrence)
    int low = 0;
    int high = nums.size() - 1;
    int leftIdx = -1;

    // binary search
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            leftIdx = mid;
            high = mid - 1;
        } else if(nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // search right 
    // (second occurrence)
    low = 0;
    high = high = nums.size() - 1;
    int rightIdx = -1;

    // binary search
    while(low <= high) {
        int mid = (low + high) / 2;
        if(nums[mid] == target) {
            rightIdx = mid;
            low = mid + 1;
        } else if(nums[mid] > target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    vector<int> result;
    result.push_back(leftIdx);
    result.push_back(rightIdx);
    return result;
}

int main() {

    return 0;
}
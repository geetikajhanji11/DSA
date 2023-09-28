#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ****** MY STRAIGHTFORWARD SOLUTION ******
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        int minNum = INT_MAX;

        // everytime, either left part will be sorted
        // or the right 
        while(low <= high) {
            int mid = (low + high) / 2;

            minNum = min(minNum, nums[mid]);

            // if left side is sorted [low, mid],
            // nums[low] is the min of that part of nums
            // compare it with curr min and be done with that part
            // go right
            if(nums[low] <= nums[mid]) {
                minNum = min(minNum, nums[low]);
                low = mid + 1;
            } 
            
            // if right side is sorted [mid, high],
            // nums[mid] is the min of that part of nums
            // which we already compared above 
            // go left
            else {
                high = mid - 1;
            }

        }

        return minNum;
    }
};

// Neetcode Solution
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        
        // not low <= high since not searching for target
        while (low < high) {
            int mid = low + (high - low) / 2;
            // nums[mid] > nums[high], min must be right
            if (nums[mid] > nums[high]) {
                // never consider mid bc know for sure not min
                low = mid + 1;
            // nums[mid] <= nums[right], min must be left
            } else {
                // consider mid still bc could be min
                high = mid;
            }
        }
        
        // low lands on correct value, never disqualified mins
        return nums[low];
    }
};

int findMin(vector<int>& nums) {
    int low = 0;
    int high = nums.size() - 1;

    int answer = INT_MAX;

    while(low <= high) {
        int mid = (low + high) / 2;

        // if entire array is sorted
        if(nums[low] <= nums[high]) {
            answer = min(answer, nums[low]);
            break;
        }

        // left side is sorted
        else if(nums[low] <= nums[mid]) {
            if(nums[low] > nums[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // right side is sorted
        else if(nums[mid] <= nums[high]) {
            answer = min(answer, nums[mid]);
            high = mid - 1;
        }
    }       
    return answer;
}

int main() {

    vector<int> nums = {3, 1, 2};
    cout<<findMin(nums);
    return 0;
}
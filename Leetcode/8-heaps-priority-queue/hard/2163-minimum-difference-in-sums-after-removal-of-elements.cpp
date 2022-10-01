/*******************************************************************
[3,19,70,23,67,29,2,78,34,12,33,9]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        priority_queue<int, vector<int>, greater<int>> minHeap; // right (top n max numbers)
        priority_queue<int> maxHeap; // left

        // filling the right sum 
        vector<long long> rightMaxSum(nums.size(), 0);
        long long rightSum = 0;

        for(int i=nums.size()-1; i>=n; i--) {
            minHeap.push(nums[i]);
            rightSum += nums[i];
            if(minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }
            if(minHeap.size() == n) {
                rightMaxSum[i] = rightSum;
            }
        }

        // finding the left sum
        long long leftSum = 0;
        long long result = LLONG_MAX;

        for(int i=0; i<nums.size()-n; i++) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];
            if(maxHeap.size() > n) {
                leftSum -= maxHeap.top(); 
                maxHeap.pop();
            }
            if(maxHeap.size() == n) {
                long long diff = leftSum - rightMaxSum[i+1];
                result = min(result, diff);
            }
        }
        return result;
    }
};

// ************** RECURSIVE SOLUTION **************
// ************** WORKS **************
// class Solution {

//     int minDiff(int i, int n, int removedSum, int left_n, int leftSum, vector<int>& nums, int &totalSum) {

//         if(n == 0 && left_n == 0) {
             
//             int sum = totalSum - removedSum;
//             int rightSum = sum - leftSum;
//             cout<<"\ntotal = "<<totalSum<<", leftSum = "<<leftSum<<", removedSum = "<<removedSum<<", rightSum = "<<rightSum;
//             return leftSum - rightSum;
//         }

//         if(i == nums.size()) return INT_MAX;

//         // remove current num
//         int diff1 = INT_MAX;
//         if(n > 0) {
//             diff1 = minDiff(i+1, n-1, removedSum + nums[i], left_n, leftSum, nums, totalSum);
//         }

//         // add current num to leftSum
//         int diff2 = INT_MAX;
//         if(left_n > 0) {
//             diff2 = minDiff(i+1, n, removedSum, left_n-1, leftSum + nums[i], nums, totalSum);
//         } else if(left_n == 0) { // n != 0
//             diff2 = minDiff(i+1, n, removedSum, left_n, leftSum, nums, totalSum);
//         }

//         return min(diff1, diff2);
//     }

// public:
//     long long minimumDifference(vector<int>& nums) {
//         int n = nums.size() / 3;
//         int totalSum = accumulate(nums.begin(), nums.end(), 0);
//         return minDiff(0, n, 0, n, 0, nums, totalSum);
//     }
// };
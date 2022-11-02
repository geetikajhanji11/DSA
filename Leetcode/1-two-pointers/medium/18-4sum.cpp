/*******************************************************************
def fourSum(self, nums, target):
    def findNsum(l, r, target, N, result, results):
        if r-l+1 < N or N < 2 or target < nums[l]*N or target > nums[r]*N:  # early termination
            return
        if N == 2: # two pointers solve sorted 2-sum problem
            while l < r:
                s = nums[l] + nums[r]
                if s == target:
                    results.append(result + [nums[l], nums[r]])
                    l += 1
                    while l < r and nums[l] == nums[l-1]:
                        l += 1
                elif s < target:
                    l += 1
                else:
                    r -= 1
        else: # recursively reduce N
            for i in range(l, r+1):
                if i == l or (i > l and nums[i-1] != nums[i]):
                    findNsum(i+1, r, target-nums[i], N-1, result+[nums[i]], results)

    nums.sort()
    results = []
    findNsum(0, len(nums)-1, target, 4, [], results)
    return results
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void twoSum(int left, int right, vector<int>& nums, long long target, vector<int> &result, vector<vector<int>> &results) {
        while(left < right) {
            long long sum = nums[left] + nums[right];
            if(sum < target) left++;
            else if(sum > target) right--;
            else {

                vector<int> arr = result;
                arr.push_back(nums[left]);
                arr.push_back(nums[right]);
                results.push_back(arr);

                left++;
                while(left < right && nums[left] == nums[left-1]) left++;
            }
        }
    }

    void kSum(int k, int left, int right, vector<int>& nums, long long target, vector<int> result, vector<vector<int>> &results) {
            
        if(k < 2) return;
        if(left >= right) return;
        if(target < (long long) nums[left] * k) return;
        if(target > (long long) nums[right] * k) return;
        
        if(k == 2) {
            twoSum(left, right, nums, target, result, results);
            return;
        }

        for(int i=left; i<=right; i++) {
            if(i == left || (i > left && nums[i] != nums[i-1])) {
                result.push_back(nums[i]);
                kSum(k-1, i+1, right, nums, target-nums[i], result, results);
                result.pop_back();
            }
        }
        
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        kSum(4, 0, nums.size()-1, nums, target, {}, results);
        return results;
    }
};
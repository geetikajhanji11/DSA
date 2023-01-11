/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(n) bucket sort
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> bucket(101, 0);
        for(int i=0; i<n; i++) {
            bucket[nums[i]]++;
        }

        for(int i=1; i<=100; i++) {
            bucket[i] += bucket[i-1];
        }

        vector<int> result(n, 0);
        for(int i=0; i<n; i++) {
            if(nums[i] == 0) continue;
            result[i] = bucket[nums[i] - 1];
        }
    
        return result;
    }
};

// O(nlogn) normal sort
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n = nums.size();

        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        unordered_map<int, int> position;
        for(int i=0; i<n; i++) {
            if(position.find(sortedNums[i]) != position.end()) continue;
            position[sortedNums[i]] = i;
        }

        vector<int> result;
        for(int num : nums) {
            result.push_back(position[num]);
        }
    
        return result;
    }
};
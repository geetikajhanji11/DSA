/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<int, int> p1, pair<int, int> p2) {
        return p1.first > p2.first;
    }
};

class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> minHeap;

        for(int i=0; i<nums.size(); i++) {
            minHeap.push({nums[i], i});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }

        set<int> s;
        while(!minHeap.empty()) {
            s.insert(minHeap.top().second);
            minHeap.pop();
        }

        vector<int> result;
        for(auto i : s) {
            result.push_back(nums[i]);
        }

        return result;
    }
};
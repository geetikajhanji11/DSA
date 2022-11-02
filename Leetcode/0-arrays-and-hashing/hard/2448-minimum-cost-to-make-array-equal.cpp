/*******************************************************************
https://www.youtube.com/watch?v=clHTLCrl7eM&ab_channel=BroCoders

Treat cost as frequency of the corresponding number

nums = [1,3,5,2]
cost = [2,3,1,4]

Translates to (in sorted order):
1,1,2,2,2,2,3,3,3,5

The median here is = 2.
So, all the array elements must be 2.
Calculate final cost according to this.

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        vector<pair<int, int>> num_and_cost;
        
        long long totalElements = 0;
        for(int i=0; i<n; i++) {
            num_and_cost.push_back({nums[i], cost[i]});
            totalElements += cost[i];
        }

        sort(num_and_cost.begin(), num_and_cost.end());

        // find the median of sorted numbers
        long long median;
        long long total = 0;
        for(int i=0; i<n; i++) {
            if(total < (totalElements + 1) / 2) {
                total += num_and_cost[i].second;
                median = num_and_cost[i].first;
            } 
        }

        // calculating the cost
        long long result = 0;
        for(auto p : num_and_cost) {
            int currNum = p.first;
            int currCost = p.second;
            result += (abs(currNum - median) * currCost);
        }

        return result;
    }
};
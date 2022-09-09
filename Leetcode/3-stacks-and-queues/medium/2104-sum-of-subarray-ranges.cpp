/*******************************************************************
https://www.youtube.com/watch?v=yAoN-EQRszk&ab_channel=KacyCodes
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(N)
class Solution {

    bool condition(int top, int num, bool isDecreasing) {
        if(isDecreasing) return num > top;
        return num < top;
    }

    long long pushToStack(stack<int> &s, int i, vector<int>& nums, bool isDecreasing) {

        long long result = 0;

        while(!s.empty() && (i == nums.size() || condition(nums[s.top()], nums[i], isDecreasing))) {
            int pop_i = s.top(); s.pop();
            int prev_i = s.empty() ? -1 : s.top();
            int next_i = i;

            int leftNumsCount = pop_i - prev_i;
            int rightNumsCount = next_i - pop_i;

            result += ((leftNumsCount * rightNumsCount) * (long long) (nums[pop_i]));

        }

        s.push(i);

        return result;
    }

public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        stack<int> decreasingStack;
        stack<int> increasingStack;

        long long sum = 0;
        for(int i=0; i<=n; i++) {
            long long a = pushToStack(decreasingStack, i, nums, true);
            long long b = pushToStack(increasingStack, i, nums, false);
            sum += (a - b);
        }

        return sum;
    }
};

// O(N^2)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();

        long long result = 0;

        for(int i=0; i<n; i++) {
            int smallest = nums[i];
            int biggest = nums[i];
            for(int j=i; j<n; j++) {
                if(nums[j] < smallest) smallest = nums[j];
                if(nums[j] > biggest) biggest = nums[j];
                result += (biggest - smallest);    
            }
        }

        return result;
    }
};
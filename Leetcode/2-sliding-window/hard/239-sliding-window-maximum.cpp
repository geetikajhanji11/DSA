/*******************************************************************
 Given int array & sliding window size k, return max sliding window
Ex. nums = [1,3,-1,-3,5,3,6,7] k = 3 -> [3,3,5,5,6,7]

Sliding window deque, ensure monotonic decr, leftmost largest

Time: O(n)
Space: O(n)


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        int i = 0;
        int j = 0;
        
        while (j < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            
            if (i > dq.front()) {
                dq.pop_front();
            }
            
            if (j + 1 >= k) {
                result.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        
        return result;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> result;
        
        int i = 0;
        int j = 0;
        
        while (j < nums.size()) {
            while (!dq.empty() && nums[dq.back()] < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(j);
            
            if (i > dq.front()) {
                dq.pop_front();
            }
            
            if (j + 1 >= k) {
                result.push_back(nums[dq.front()]);
                i++;
            }
            j++;
        }
        
        return result;
    }
};

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> q;

    int left = 0;
    int right = k-1;

    for(int i=left; i<=right; i++) {
        int num = nums[i];
        if(q.empty()) {
            q.push_back(num);
            continue;
        }
        if(num <= q.back()) {
            q.push_back(num);
        } else {
            while(!q.empty() && q.back() < num) q.pop_back();
            q.push_back(num);
        }
    }

    vector<int> result;
    result.push_back(q.front());

    right++;
    while(right < nums.size()) {

        if(nums[left] == q.front()) {
            q.pop_front();
        }
        left++;

        int num = nums[right];
        if(num <= q.back()) {
            q.push_back(num);
        } else {
            while(!q.empty() && q.back() < num) q.pop_back();
            q.push_back(num);
        }

        result.push_back(q.front());
        right++;
    }

    return result;
}

int main() {

    return 0;
}
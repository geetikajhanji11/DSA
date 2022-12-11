/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** USING MULTISET **************
// exact same logic as median from data stream, but with deletion
// of the number moving out of the window from any one of the heaps
// which takes O(logn) [can be achieved with multiset]. 
// overall complexity = O(nlogk)
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        
        multiset<int> window; // stores numbers currently in window
        vector<double> medians;

        for(int i=0; i<nums.size(); i++) {

            window.insert(nums[i]);

            if(window.size() > k) {
                window.erase(window.find(nums[i-k]));
            }

            if(window.size() == k) {
                auto mid_plus_1 = next(window.begin(), k/2);
                auto mid = prev(mid_plus_1, 1 - k%2);

                double median = ((double) *mid + (double) *mid_plus_1) / 2.0;
                medians.push_back(median);
            }
        }

        return medians;
    }
};

// ************** USING PRIORITY QUEUE **************
class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> medians;
        unordered_map<int, int> hash;                          // count numbers to be deleted
        priority_queue<int, vector<int>> bheap;                // heap on the bottom
        priority_queue<int, vector<int>, greater<int>> theap;  // heap on the top
        
        int i = 0;
        
        // Initialize the heaps
        while (i < k)  { bheap.push(nums[i++]); }
        for (int count = k/2; count > 0; --count) {
            theap.push(bheap.top()); bheap.pop();
        }
        
        while (true) {
            // Get median
            if (k % 2) medians.push_back(bheap.top());
            else medians.push_back( ((double)bheap.top() + theap.top()) / 2 );
            
            if (i == nums.size()) break;
            int m = nums[i-k], n = nums[i++], balance = 0;
            
            // What happens to the number m that is moving out of the window
            if (m <= bheap.top())  { --balance;  if (m == bheap.top()) bheap.pop(); else ++hash[m]; }
            else                   { ++balance;  if (m == theap.top()) theap.pop(); else ++hash[m]; }
            
            // Insert the new number n that enters the window
            if (!bheap.empty() && n <= bheap.top())  { ++balance; bheap.push(n); }
            else                                     { --balance; theap.push(n); }
            
            // Rebalance the bottom and top heaps
            if      (balance < 0)  { bheap.push(theap.top()); theap.pop(); }
            else if (balance > 0)  { theap.push(bheap.top()); bheap.pop(); }
            
            // Remove numbers that should be discarded at the top of the two heaps
            while (!bheap.empty() && hash[bheap.top()])  { --hash[bheap.top()]; bheap.pop(); }
            while (!theap.empty() && hash[theap.top()])  { --hash[theap.top()]; theap.pop(); }
        }
        
        return medians;
    }
};
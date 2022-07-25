/*******************************************************************
Design a class to find the kth largest element in a stream

Min heap & maintain only k elements, top will always be kth largest
Ex. nums = [6,2,3,1,7], k = 3 -> [1,2,3,6,7] -> [3,6,7]

Time: O(n log n + m log k) -> n = length of nums, m = add calls
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class KthLargest {
    int k;
    priority_queue <int, vector<int>, greater<int> > pq; // min heap

public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) pq.push(num);
        while(pq.size() > k) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() == k) return pq.top();
        else if(pq.size() > k) {
            pq.pop();
            return pq.top();
        }
        return INT_MIN; // does not exist since pq.size() < k
    }
};

int main() {

    return 0;
}
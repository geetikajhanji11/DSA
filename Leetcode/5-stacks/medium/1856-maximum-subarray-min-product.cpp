/*******************************************************************
SIMILAR => 84 - LARGEST REACTANGLE IN HISTOGRAM 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Element {
public:
    int startIdx;
    int minValue;
    Element(int startIdx, int value) {
        this->startIdx = startIdx;
        this->minValue = value;
    }
};

int maxSumMinProduct(vector<int>& nums) {

    int n = nums.size();

    // monotonically increasing stack
    stack<Element> s;
    long result = 0;

    // prefix sums from ith idx to last idx
    vector<long> prefixSum;
    prefixSum.push_back(0);
    for(int num : nums) {
        prefixSum.push_back(num + prefixSum[prefixSum.size()-1]);
    }

    // for each value in nums, consider it as the min of subarray
    for(int i=0; i<nums.size(); i++) {

        int poppedStartIdx = -1;
        while(!s.empty() && s.top().minValue > nums[i]) {
            poppedStartIdx = s.top().startIdx;
            long subarraySum = prefixSum[i] - prefixSum[s.top().startIdx];
            result = max(result, subarraySum * s.top().minValue);
            s.pop();
        }

        if(poppedStartIdx != -1) {
            s.push(Element(poppedStartIdx, nums[i]));
        } else {
            s.push(Element(i, nums[i]));
        }
    }

    // all elements left in the stack
    // can make a valid subarray upto end of the nums array
    while(!s.empty()) {
        long subarraySum = prefixSum[n] - prefixSum[s.top().startIdx];
        result = max(result, subarraySum * s.top().minValue);
        s.pop();
    }

    return result % 1000000007;
}

int main() {

    return 0;
} 
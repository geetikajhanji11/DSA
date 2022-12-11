/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> cumulativeSum;
    int totalSum;

    int binarySearch(int randomNum) {
        int low = 0;
        int high = cumulativeSum.size() - 1;

        int idx = 0;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(randomNum < cumulativeSum[mid]) {
                idx = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return idx;
    }

public:
    Solution(vector<int>& w) {
        int sum = 0;
        for(int weight : w) {
            sum += weight;
            this->cumulativeSum.push_back(sum);
        }
        this->totalSum = sum;
    }
    
    int pickIndex() {
        int randomNumber = rand() % totalSum;
        return binarySearch(randomNumber);
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
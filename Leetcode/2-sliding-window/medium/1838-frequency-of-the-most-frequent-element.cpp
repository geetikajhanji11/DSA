/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/* **************  BRUTE - FORCE ****************
    int maxFrequency(vector<int>& nums, int k) {

        int n = nums.size();
        sort(nums.begin(), nums.end());

        int maxFreq = 1;
        for(int i=n-1; i>=0; i--) {
            int ctr = 0;
            int freq = 1;
            for(int j=i-1; j>=0; j--) {
                int diff = nums[i] - nums[j];
                ctr += diff;
                freq++;
                if(ctr <= k) {
                    maxFreq = max(maxFreq, freq);
                } else break;
            }
        }        

        return maxFreq;
    }
*/


// **************** MAIN LOGIC ****************
int maxFrequency(vector<int>& nums, int k) {

    int n = nums.size();
    sort(nums.begin(), nums.end());

    // nums[right] will be the number 
    // we are checking if is the number having max freq
    long windowSum = 0;
    long long_k = k;
    int maxFreq = 0;

    int left = 0;
    int right = 0; 

    while(right < n) {

        windowSum += nums[right];

        // contract if invalid
        // CONDITION: nums[right] * (right - left + 1) > windowSum + k
        while(((long) nums[right] * (long)(right - left + 1)) - windowSum > long_k) {
            windowSum -= nums[left];
            left++;
        }

        // check if found max freq
        maxFreq = max(maxFreq, (right - left + 1));
        right++;
    }

    return maxFreq;
}

int main() {

    return 0;
}
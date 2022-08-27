/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {

        int n = nums.size();

        vector<int> LISLengthDP(n);
        vector<int> countDP(n);

        LISLengthDP[n-1] = 1;
        countDP[n-1] = 1;

        int overAllMaxLISLength = 1;

        for(int i=n-2; i>=0; i--) {

            // filling LISLengthDP
            int maxLISLength = 0;
            for(int j=i+1; j<n; j++) {
                if(nums[j] > nums[i]) {
                    maxLISLength = max(maxLISLength, LISLengthDP[j]);
                }   
            }
            LISLengthDP[i] = maxLISLength + 1;
            overAllMaxLISLength = max(overAllMaxLISLength, LISLengthDP[i]);

            // filling countDP
            int sum = 0;
            for(int j=i+1; j<n; j++) {
                if(nums[j] > nums[i] && LISLengthDP[j] == maxLISLength) {
                    sum += countDP[j];
                }   
            }

            if(sum == 0) countDP[i] = 1;
            else countDP[i] = sum;

        }

        int result = 0;
        for(int i=0; i<n; i++) {
            if(LISLengthDP[i] == overAllMaxLISLength) {
                result += countDP[i];
            }
        }

        return result;
    }
};
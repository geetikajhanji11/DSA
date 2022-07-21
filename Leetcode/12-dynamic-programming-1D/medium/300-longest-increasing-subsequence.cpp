/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);

    int result = 1;
    for(int i=n-1; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            if(nums[i] < nums[j]) {
                dp[i] = max(dp[i], 1 + dp[j]);
                result = max(result, dp[i]);
            }
        }
    }

    return result;
}

int main() {

    return 0;
}
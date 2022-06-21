/*******************************************************************
 * MAX NON ADJACENT SUM
 * 
 * Given an array of positive integers, find the maximum sum of
 * non adjacent elements in the array
 * 
 * Input
 *      arr = {6, 10, 12, 7, 9, 14}
 * 
 * Output
 *      32 [6 + 12 + 14]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top-down approach
int max_non_adj_sum(int i, vector<int> arr, vector<int> &dp) {

    if(i == 0) return arr[0];
    if(i < 0) return 0;
  
    if(dp[i] != 0) return dp[i];

    int include = arr[i] + max_non_adj_sum(i-2, arr, dp);
    int exclude = max_non_adj_sum(i-1, arr, dp);

    dp[i] = max(include, exclude);

    return dp[i];

}

// bottom-up approach
int max_non_adj_sum(vector<int> arr) {
    vector<int> dp(arr.size(), 0);
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i=2; i<arr.size(); i++) {
        int include = arr[i] + dp[i-2];
        int exclude = dp[i-1];
        dp[i] = max(include, exclude);
    }

    return dp[arr.size() - 1];
}

int main() {

    vector<int> arr = {6, 10, 12, 7, 9, 14};
    vector<int> dp(arr.size(), 0);
    cout<<max_non_adj_sum(arr.size() - 1, arr, dp)<<endl;
    cout<<max_non_adj_sum(arr);

    return 0;
}
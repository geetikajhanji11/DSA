/*******************************************************************
 * MIN ARRAY JUMP
 * 
 * Given an array of positive integers, where each element 
 * represents the max number of steps you can jump forward in
 * the array.
 * Find minimum jumps needed to reach the final index.
 * 
 * Input
 *  arr = [3, 4, 2, 1, 2, 3, 7, 1, 1, 1, 2, 5]
 * 
 * Output
 *  4 {3 -> 4 -> 2 -> 7 -> 5}
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// top - down apprach
int min_jump(int curr_jump_index, vector<int> arr, vector<int> &dp) {
    
    // base cases
    if(curr_jump_index == arr.size() - 1) return 0;
    if(curr_jump_index >= arr.size()) return INT_MAX;

    // rec case
    if(dp[curr_jump_index] != 0) return dp[curr_jump_index];

    int curr_jump = arr[curr_jump_index];
    int ans = INT_MAX;
    for(int i=1; i<=curr_jump; i++) {
        int rem_jump = min_jump(curr_jump_index + i, arr, dp);
        if(rem_jump != INT_MAX) {
            ans = min(ans, rem_jump);
        }
    }

    dp[curr_jump_index] = 1 + ans;
    return dp[curr_jump_index];
}

int main() {

    vector<int> jumps = {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    vector<int> dp(jumps.size()+1, 0);

    cout<<min_jump(0, jumps, dp);

    return 0;
}
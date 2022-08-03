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
/*
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
*/

// ********** TOP-DOWN APPROACH **********
int min_jumps(int i, vector<int> &jumps, vector<int> &dp) {

    if(i == jumps.size()-1) return 0;
    if(i >= jumps.size()) return INT_MAX;

    if(dp[i] != INT_MAX) return dp[i];

    int total_jumps = jumps[i];
    int ans = INT_MAX;
    for(int jump=1; jump<=total_jumps; jump++) {
        int remaining = min_jumps(i+jump, jumps, dp);
        if(remaining == INT_MAX) continue;
        ans = min(ans, remaining);
    }

    if(ans == INT_MAX) return dp[i] = INT_MAX;
    return dp[i] = ans + 1;

}

// ********** BOTTOM-UP APPROACH **********
int min_jumps(vector<int> &jumps) {
    
    int n = jumps.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;

    for(int i=n-2; i>=0; i--) {
        int total_jumps = jumps[i];
        int ans = dp[i];
        for(int jump=1; jump<=total_jumps; jump++) {
            if(i+jump >= n) break;
            ans = min(ans, dp[i+jump]);
        }
        if(ans == INT_MAX) continue;
        dp[i] = ans + 1;
    }

    return dp[0];
}

int main() {

    vector<int> jumps = {3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
    // vector<int> dp(jumps.size()+1, 0);
    vector<int> dp(jumps.size()+1, INT_MAX);

    cout<<min_jumps(0, jumps, dp);

    return 0;
}
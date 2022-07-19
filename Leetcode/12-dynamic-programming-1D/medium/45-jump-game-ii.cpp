/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ---------------- TOP-DOWN APPROACH ----------------
// int min_jumps(int i, vector<int>& nums, vector<int> &dp) {
//     int n = nums.size();
//     if(i == n-1) return 0;
//     if(dp[i] != INT_MAX) return dp[i];

//     int jumps = nums[i];
//     int ans = INT_MAX;
//     for(int jump=1; jump<=jumps; jump++) {
//         if(i+jump >= n) break;
//         int remaining_jumps = min_jumps(i+jump, nums, dp);
//         if(remaining_jumps != INT_MAX) {
//             ans = min(ans, 1 + remaining_jumps);
//         }
//     }

//     return dp[i] = ans;
// }

// int jump(vector<int>& nums) {
//     vector<int> dp(nums.size()+1, INT_MAX);
//     int ans =  min_jumps(0, nums, dp);

//     for(int num : dp) cout<<num<<" ";
//     return ans == INT_MAX ? -1 : ans;
// }

// ---------------- BOTTOM-UP APPROACH ----------------
int jump(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;
    for(int i=n-2; i>=0; i--) {
        int jumps = nums[i];
        for(int jmp=1; jmp<=jumps; jmp++) {
            if(i+jmp >= n) break;
            if(dp[i+jmp] == INT_MAX) continue;
            dp[i] = min(dp[i], 1 + dp[i+jmp]);
        }
    }
    return dp[0] == INT_MAX ? -1 : dp[0];
}


int main() {

    vector<int> nums = {3,2,1,0,4};
    cout<<jump(nums);
    return 0;
}
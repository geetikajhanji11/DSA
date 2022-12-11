#include<bits/stdc++.h>
using namespace std;

// Greedy Approach O(n)
bool canJump(vector<int>& nums) {
    int goal_index = nums.size() - 1;
    for(int i=goal_index-1; i>=0; i--) {
        int jumps = nums[i];
        if(i + jumps >= goal_index) {
            goal_index = i;
        } 
    }

    if(goal_index == 0) return true;
    return false;
}

// DP Approach O(n^2)
bool canJump(vector<int>& nums) {

    if(nums.size() == 1) return true;

    int last_index = nums.size() - 1;
    int curr = nums.size() - 2;

    vector<bool> dp(nums.size(), false);
    dp[last_index] = true;

    while(curr >= 0) {
        int jumps = nums[curr];
        for(int jump=1; jump<=jumps; jump++) {
            if(curr + jump < nums.size()) {
                dp[curr] = dp[curr] || dp[curr+jump];
            }
            if(dp[curr] == true) break;
        }
        curr--;
    }

    return dp[0];
}

int main() {

    return 0;
}
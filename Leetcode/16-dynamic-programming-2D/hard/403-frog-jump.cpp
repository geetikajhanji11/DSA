/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// ---------------- TOP-DOWN APPROACH ----------------
// bool frog_jumps(int i, int prev_jump, vector<bool> is_water, vector<int> dp) {
    
//     if(i >= is_water.size()) return false;
//     if(i == is_water.size()-1) return true;
//     if(is_water[i]) return false;

//     if(dp[i] != -1) return dp[i];

//     int jump_1 = prev_jump-1;
//     int jump_2 = prev_jump;
//     int jump_3 = prev_jump+1;
    
//     bool can_jump_1 = false;
//     if(i + jump_1 != i) can_jump_1 = frog_jumps(i+jump_1, jump_1, is_water, dp);
//     bool can_jump_2 = frog_jumps(i+jump_2, jump_2, is_water, dp);
//     bool can_jump_3 = frog_jumps(i+jump_3, jump_3, is_water, dp);

//     return dp[i] = can_jump_1 || can_jump_2 || can_jump_3;
// }

// bool canCross(vector<int>& stones) {
//     int n = stones.size();
//     if(stones[1] != 1) return false;
//     int last_pos = stones[n-1];
//     vector<bool> is_water(last_pos+1, true);
//     vector<int> dp(last_pos+1, -1);

//     for(int stone : stones) is_water[stone] = false;

//     return frog_jumps(1, 1, is_water, dp);
// }


// ---------------- TOP-DOWN OPTIMIZED APPROACH ----------------
bool can_jump(int last_index, int curr_index, vector<int>& stones, vector<vector<int>> &dp) {

    if(curr_index == stones.size() - 1) return true;
    if(dp[last_index][curr_index] != -1) return dp[last_index][curr_index];

    int last_jump = stones[curr_index] - stones[last_index];

    bool ans = false;
    for(int i=curr_index+1; i<stones.size(); i++) {
        int next_jump = stones[i] - stones[curr_index];
        if(next_jump == last_jump-1 || next_jump == last_jump || next_jump == last_jump+1) { 
            ans = ans || can_jump(curr_index, i, stones, dp);
        }
    }

    return dp[last_index][curr_index] = ans;
}

bool canCross(vector<int>& stones) {
    int n = stones.size();
    if(stones[1] != 1) return false;
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return can_jump(0, 1, stones, dp);
}

int main() {

    vector<int> stones1 = {0,1,3,5,6,8,12,17};
    vector<int> stones2 = {0,1,2,3,4,8,9,11};
    if(canCross(stones1)) cout<<"\ntrue";
    else cout<<"\nfalse";

    if(canCross(stones2)) cout<<"\ntrue";
    else cout<<"\nfalse";
    return 0;
}
/*******************************************************************

// DP SOLUTION
// WORKS => But can be optimized with BFS

bool isAbleToReach(int i, string s, int minJump, int maxJump, vector<int> &dp) {
    if(i == s.length()-1) return true;
    if(i >= s.length()) return false;

    if(dp[i] != -1) return dp[i];

    if(s[i] == '1') return dp[i] = false;

    for(int jump=minJump; jump<=maxJump; jump++) {
        if(isAbleToReach(i+jump, s, minJump, maxJump, dp)) {
            return dp[i] = true;
        }
    }

    return dp[i] = false;
}

bool canReach(string s, int minJump, int maxJump) {
    if(s[s.length()-1] == '1') return false;
    vector<int> dp(s.length(), -1); 
    return isAbleToReach(0, s, minJump, maxJump, dp);
}
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool canReach(string s, int minJump, int maxJump) {

    int n = s.length();
    if(s[n-1] == '1') return false;

    queue<int> q;
    int farthestIdx = 0;
    q.push(0);

    while(!q.empty()) {

        int i = q.front();
        q.pop();

        // if (i + minJump) < farthestIdx, we have already explored this idx
        // so we will want to explore (farthestIdx + 1)
        int start = max(i + minJump, farthestIdx + 1);

        // if (i + maxJump) is out of bounds,
        // set end = n - 1
        int end = min(i + maxJump, n - 1);

        for(int j=start; j<=end; j++) {
            if(s[j] == '0') {
                q.push(j);
                if(j == n-1) return true;
            }
        }
        farthestIdx = i + maxJump;
    }

    return false;
}

int main() {

    return 0;
}
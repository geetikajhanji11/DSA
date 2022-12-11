/*******************************************************************
SAME AS = LEETCODE 698 - PARTITION TO K EQUAL SUM SUBSETS
HERE, K = 4
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool backtrack(int i, int subset_sum, int k, int &target, vector<int>& matchsticks, vector<bool> &visited, map<vector<bool>, bool> &dp) {
    if(k == 0) return true;

    if(dp.find(visited) != dp.end()) return dp[visited];

    if(subset_sum == target) {
        return dp[visited] = backtrack(0, 0, k-1, target, matchsticks, visited, dp);
    }

    for(int j=i; j<matchsticks.size(); j++) {
        if(visited[j] || subset_sum + matchsticks[j] > target) continue;
        visited[j] = true;
        if(backtrack(j+1, subset_sum + matchsticks[j], k, target, matchsticks, visited, dp)) return true;
        visited[j] = false;
    }

    return dp[visited] = false;
}

bool makesquare(vector<int>& matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if(sum % 4 != 0) return false;

    sort(matchsticks.begin(), matchsticks.end());
    
    int target = sum / 4;
    vector<bool> visited(matchsticks.size(), false);

    map<vector<bool>, bool> dp;

    return backtrack(0, 0, 4, target, matchsticks, visited, dp);
}

int main() {

    return 0;
}
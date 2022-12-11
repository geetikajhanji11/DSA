/*******************************************************************
Given distinct int array & a target, return list of all unique combos 
that sum to target
Ex. candidates = [2,3,6,7] target = 7 -> [[2,2,3],[7]]

Backtracking, generate all combo sums, push/pop + index checking to 
explore new combos

Time: O(n^target)
Space: O(target)

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> curr;
        vector<vector<int>> result;
        
        dfs(candidates, target, 0, 0, curr, result);
        return result;
    }
private:
    void dfs(vector<int>& candidates, int target, int sum, int start, vector<int>& curr, vector<vector<int>>& result) {
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(curr);
            return;
        }
        for (int i = start; i < candidates.size(); i++) {
            curr.push_back(candidates[i]);
            dfs(candidates, target, sum + candidates[i], i, curr, result);
            curr.pop_back();
        }
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int i, int sum, vector<int> curr_candidates, vector<int>& candidates, int target, vector<vector<int>> &result) {

    if(sum > target) return;

    if(sum == target) {
        result.push_back(curr_candidates);
        return;
    }

    for(int index=i; index<candidates.size(); index++) {
        int candidate = candidates[index];
        curr_candidates.push_back(candidate);
        dfs(index, sum+candidate, curr_candidates, candidates, target, result);
        curr_candidates.pop_back();
    }
    
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

    vector<vector<int>> result;
    vector<int> curr_candidates;
    
    sort(candidates.begin(), candidates.end());
    dfs(0, 0, curr_candidates, candidates, target, result);

    return result;
}

int main() {

    return 0;
}
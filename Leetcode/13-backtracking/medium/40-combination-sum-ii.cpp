/*******************************************************************
Given array & a target, find all unique combos that sum to target, nums can only be used once
Ex. candidates = [10,1,2,7,6,1,5], target = 8 -> [[1,1,6],[1,2,5],[1,7],[2,6]]

Backtracking, generate all combo sums, push/pop + index checking to explore new combos

Time: O(2^n)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int i, vector<int> curr, vector<int>& candidates, int target, vector<vector<int>> &result) {

        if(target < 0) return;

        if(target == 0) {
            result.push_back(curr);
            return;
        }
        
        if(i >= candidates.size()) return;

        // include current 
        curr.push_back(candidates[i]);
        dfs(i+1, curr, candidates, target - candidates[i], result);
        curr.pop_back();

        // exclude current (skip duplicate elements)
        int idx = i + 1;
        while(idx < candidates.size() && candidates[idx] == candidates[idx-1]) idx++;
        dfs(idx, curr, candidates, target, result);

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> curr;

        dfs(0, curr, candidates, target, result);

        return result;
    }
};


// ************* SAME LOGIC BUT DIFFERENT STYLE OF WRITING *************
void dfs(int i, vector<int> curr, vector<int>& candidates, int target, vector<vector<int>> &result) {

    if(target < 0) return;

    if(target == 0) {
        result.push_back(curr);
        return;
    }

    for(auto idx=i; idx<candidates.size(); idx++) {
        if(idx > i && candidates[idx] == candidates[idx-1]) continue;

        curr.push_back(candidates[idx]);
        dfs(idx+1, curr, candidates, target-candidates[idx], result);
        curr.pop_back();

    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());
    vector<vector<int>> result;
    vector<int> curr;

    dfs(0, curr, candidates, target, result);

    return result;
}
/*******************************************************************
Given an integer array of unique elements, return all possible subsets 
(the power set)
Ex. nums = [1,2,3] -> [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Backtracking, generate all combinations, push/pop + index checking 
to explore new combos

Time: O(n x 2^n)
Space: O(n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// -------- BACKTRACKING SOLUTION --------
void dfs(int i, vector<int> curr, vector<int>& nums, vector<vector<int>>& result) {

    // reached the last index, over
    if(i == nums.size()) {
        result.push_back(curr);
        return;
    }

    // exclude current number
    dfs(i+1, curr, nums, result);

    // include current number
    curr.push_back(nums[i]);
    dfs(i+1, curr, nums, result);
    
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;

    dfs(0, curr, nums, result);

    return result;
}



// -------- SET SOLUTION --------
// Start empty => []
// Adding 1 => [], [1]
// Adding 2 => [], [1], [2], [1, 2]
// Adding 3 => [], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    result.push_back({});
    vector<vector<int>> temp_result = result;

    for(int num : nums) {
        for(vector<int> curr : result) {
            curr.push_back(num);
            temp_result.push_back(curr);
        }
        result = temp_result;
    }
    return  result;
}


int main() {

    return 0;
}
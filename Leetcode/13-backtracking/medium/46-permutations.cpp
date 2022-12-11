/*******************************************************************

Given array of distinct integers, return all the possible permutations
Ex. nums = [1,2,3] -> [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Permute by swapping i/start, DFS from this point, backtrack to undo swap

Time: O(n x n!)
Space: O(n!)


class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        dfs(nums, 0, result);
        return result;
    }
private:
    void dfs(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size()) {
            result.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1, result);
            swap(nums[i], nums[start]);
        }
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ******************** SWAP APPROACH ******************** 
void dfs(int i, vector<int> &nums, vector<vector<int>> &result) {

    if(i == nums.size()) {
        result.push_back(nums);
        return;
    }

    for(int j=i; j<nums.size(); j++) {
        swap(nums[i], nums[j]);
        dfs(i+1, nums, result);
        swap(nums[i], nums[j]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    dfs(0, nums, result);
    return result;
}

// ******************** VISITED APPROACH ******************** 
void dfs(vector<int> curr, vector<int>& nums, unordered_set<int> visited, vector<vector<int>> &result) {

    if(curr.size() == nums.size()) {
        result.push_back(curr);
        return;
    }

    for(int num : nums) {
        if(visited.find(num) == visited.end()) {
            visited.insert(num);
            curr.push_back(num);
            dfs(curr, nums, visited, result);
            curr.pop_back();
            visited.erase(num);
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;
    unordered_set<int> visited;
    dfs(curr, nums, visited, result);
    return result;
}

int main() {

    return 0;
}
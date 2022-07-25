/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<int> curr, vector<int>& nums, vector<vector<int>> &result) {
    if(i == nums.size()) {
        result.push_back(curr);
        return;
    }
    
    // include the current number
    curr.push_back(nums[i]);
    dfs(i+1, curr, nums, result);
    curr.pop_back();
    
    // don't include current number
    while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
    dfs(i+1, curr, nums, result);   
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> result;
    vector<int> curr;

    dfs(0, curr, nums, result);

    return result;

}

int main() {

    return 0;
}
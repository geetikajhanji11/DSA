/**************************************************************

https://www.youtube.com/watch?v=s7AvT7cGdSo&ab_channel=NeetCode

PERMUTATIONS

Given an array nums of distinct integers, return all the possible 
permutations. You can return the answer in any order.

Example 1:
    Input: nums = [1,2,3]
    Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
    Input: nums = [0,1]
    Output: [[0,1],[1,0]]

Example 3:
    Input: nums = [1]
    Output: [[1]]

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

// --------------------- SWAP APPROACH -----------------------------
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

// ------------------ VISITED APPROACH --------------------------------


void recur(vector<vector<int>> &result, vector<int> nums, vector<int> curr, vector<bool> visited) {

    // base case
    if(curr.size() == nums.size()) {
        result.push_back(curr);
        return;
    }

    // recursive case
    for(int i=0; i<nums.size(); i++) {
        if(!visited[i]) {
            curr.push_back(nums[i]);
            visited[i] = true;
            recur(result, nums, curr, visited);
            visited[i] = false;
            curr.pop_back();
        }
    }
    
}

vector<vector<int>> permutations(vector<int> nums) {
    vector<vector<int>> result;
    vector<bool> visited(nums.size(), false);
    vector<int> curr;

    recur(result, nums, curr, visited);

    return result;
    
}

// main function 
int main() {
    
    vector<int> nums{1, 2, 3};
    vector<vector<int>> result = permutations(nums);
    for(vector<int> res : result) {
        for(int num : res) {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    return 0;
    
}
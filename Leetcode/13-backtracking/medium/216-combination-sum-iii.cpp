/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void dfs(int num, vector<int> curr, int target, int &k, vector<vector<int>> &result) {

        if(target < 0) return;
        if(curr.size() > k) return;

        if(curr.size() == k && target == 0) {
            result.push_back(curr);
            return;
        }

        if(num == 10) return;
        
        // include this number
        curr.push_back(num);
        dfs(num + 1, curr, target - num, k, result);
        curr.pop_back();

        // exclude this number
        dfs(num + 1, curr, target, k, result);
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        dfs(1, {}, n, k, result);
        return result;
    }
};
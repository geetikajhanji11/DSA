/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int i, vector<int> curr, int n, int k, vector<vector<int>> &result) {
        if(curr.size() == k) {
            result.push_back(curr);
            return;
        }

        for(int num=i; num<=n; num++) {
            curr.push_back(num);
            dfs(num+1, curr, n, k, result);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        dfs(1, {}, n, k, result);
        return result;
    }
};
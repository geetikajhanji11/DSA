/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool in_bounds(int i, int j, vector<vector<int>>& m) {
    return i >= 0 && i < m.size() && j >= 0 && j < m[0].size();
}

void dfs(int i, int j, vector<vector<int>>& m, string curr_path, vector<string> &result) {

    if(!in_bounds(i, j, m)) return;
    if(m[i][j] == 0) return;

    if(i == m.size()-1 && j == m[0].size()-1) {
        result.push_back(curr_path);
        return;
    }

    m[i][j] = 0; // marking as visited

    dfs(i+1, j, m, curr_path + 'D', result);
    dfs(i-1, j, m, curr_path + 'U', result);
    dfs(i, j-1, m, curr_path + 'L', result);
    dfs(i, j+1, m, curr_path + 'R', result);

    m[i][j] = 1; // backtrack
}

vector<string> findPath(vector<vector<int>> &m, int n) {

    vector<string> result;
    string curr_path = "";

    dfs(0, 0, m, curr_path, result);

    return result;

}

int main() {

    vector<vector<int>> m = {
        {1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}
    };

    
    auto res = findPath(m, m.size());

    cout<<"\nresult\n";
    for(string s : res) cout<<s<<" ";
    return 0;
}
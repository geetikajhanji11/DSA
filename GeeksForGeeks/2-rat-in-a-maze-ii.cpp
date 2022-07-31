/*******************************************************************
https://www.geeksforgeeks.org/rat-in-a-maze-backtracking-2/
SIMILAR TO THIS
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool in_bounds(int i, int j, int n) {
    return i >= 0 && i < n && j >= 0 && j < n;
}

bool dfs(int i, int j, vector<vector<char>> &c, vector<vector<int>> &value, vector<int> &result, int &n) {

    if(!in_bounds(i, j, n)) return false;
    if(c[i][j] == 'X') return false;

    if(i == n-1 && j == n-1) {
        result.push_back(value[i][j]);
        return true;
    }
    
    // moves right
    if(dfs(i, j+1, c, value, result, n)) {
        result.push_back(value[i][j]);
        return true;
    }

    // moves down
    if(dfs(i+1, j, c, value, result, n)) {
        result.push_back(value[i][j]);
        return true;
    }

    return false;

}

vector<int> findPath(int n, vector<vector<char>> c) {
    vector<vector<int>> value;
    int ctr = 1;
    for(int i=0; i<n; i++) {
        vector<int> row;
        for(int j=0; j<n; j++) {
            row.push_back(ctr);
            ctr++;
        }
        value.push_back(row);
    }

    vector<int> result;
    

    dfs(0, 0, c, value, result, n);

    reverse(result.begin(), result.end());

    return result;
   
}

int main() {

    vector<vector<char>> c = {
        {'O', 'O', 'X', 'O'},
        {'O', 'X', 'O', 'O'},
        {'O', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'O'},
    };  
    int n = c.size();

    auto res = findPath(n, c);
    for(int num : res) cout<<num<<" ";

    return 0;
}

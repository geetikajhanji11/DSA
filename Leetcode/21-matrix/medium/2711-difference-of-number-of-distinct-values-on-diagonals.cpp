/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {

    bool inBounds(int i, int j, int m, int n) {
        return i >= 0 && i < m && j >= 0 && j < n;
    }

public:

    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        int m = grid.size();  // number of rows
        int n = grid[0].size();  // number of columns

        // Initialize the topLeft and bottomRight matrices with zeros
        vector<vector<unordered_set<int>>> topLeft(m, vector<unordered_set<int>>(n, unordered_set<int>()));
        vector<vector<unordered_set<int>>> bottomRight(m, vector<unordered_set<int>>(n, unordered_set<int>()));
        

        // Calculate the values for the topLeft matrix
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if(!inBounds(r-1, c-1, m, n)) continue; 

                unordered_set newSet = topLeft[r-1][c-1];
                newSet.insert(grid[r-1][c-1]);
                
                topLeft[r][c] = newSet;
            }
        }

        // Calculate the values for the bottomRight matrix
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if(!inBounds(r+1, c+1, m, n)) continue; 

                unordered_set newSet = bottomRight[r+1][c+1];
                newSet.insert(grid[r+1][c+1]);
                
                bottomRight[r][c] = newSet;
            }
        }

        // Calculate the answer matrix based on the topLeft and bottomRight matrices
        vector<vector<int>> answer(m, vector<int>(n, 0));
        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                answer[r][c] = abs((int)topLeft[r][c].size() - (int)bottomRight[r][c].size());
            }
        }

        return answer;
    }
};



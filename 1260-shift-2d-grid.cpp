/*******************************************************************
        // k = 4                    9
        // rows = 4, cols = 4       3,3

        // 4 / 4 = 1                k/rows [9/3] = 3   3%rows [3%3] = (0)
        // 4 % 4 = 0                k%cols [9%3] = (0)

        // 0, 0
        // 1, 0

        // k = 7
        // rows = 3, cols = 4

        // 7/3 = 2%3 = 1
        // 7%4 = 3
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        int start_i = (k / cols) % rows;
        int start_j = k % cols;

        vector<vector<int>> result(rows, vector<int>(cols, 0));

        int og_i = 0;
        int og_j = 0;

        int i = start_i;
        int j = start_j;

        for(; i<rows; i++) {
            for(; j<cols; j++) {
                result[i][j] = grid[og_i][og_j];
                og_j++;
                if(og_j == cols) {
                    og_i++;
                    og_j = 0;
                } 
            }
            j=0;
        }

        if(og_i == rows) return result;

        i = 0;
        j = 0;
        while(og_i != rows) {
            result[i][j] = grid[og_i][og_j];

            og_j++;
            if(og_j == cols) {
                og_i++;
                og_j = 0;
            } 

            j++;
            if(j == cols) {
                i++;
                j = 0;
            } 

        }

        return result;
    }
};
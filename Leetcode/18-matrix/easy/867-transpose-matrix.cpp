/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // logic for in-place and n = m
        if(rows == cols) {
            for(int i=0; i<rows; i++) {
                for(int j=0; j<cols; j++) {
                    if(i < j) {
                        swap(matrix[i][j], matrix[j][i]);
                    }
                }
            }
            return matrix;
        }
        
        // logic for n != m
        vector<vector<int>> transpose(cols, vector<int>(rows, 0));
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                transpose[j][i] = matrix[i][j];
            }
        }
        return transpose;
    }
};
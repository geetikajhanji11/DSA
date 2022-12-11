/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void sortDiagonal(int row, int col, vector<vector<int>>& mat) {
        vector<int> temp;
        int i, j;

        i = row;
        j = col;
        while(i < mat.size() && j < mat[0].size()) {
            temp.push_back(mat[i][j]);
            i++;
            j++;
        }

        sort(temp.begin(), temp.end());

        i = row;
        j = col;
        int k = 0;
        while(i < mat.size() && j < mat[0].size()) {
            mat[i][j] = temp[k];
            k++;
            i++;
            j++;
        }
    }

public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> sortedMatrix;

        // top row
        for(int j=0; j<mat[0].size(); j++) {
            sortDiagonal(0, j, mat);
        }

        // first col
        for(int i=1; i<mat.size(); i++) {
            sortDiagonal(i, 0, mat);
        }

        return mat;

    }
};
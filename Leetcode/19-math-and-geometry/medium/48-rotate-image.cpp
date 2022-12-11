/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void transpose(vector<vector<int>>& matrix) {
    for(int i=0; i<matrix.size(); i++) {
        for(int j=0; j<matrix[0].size(); j++) {
            if(i < j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}

void inverse(vector<vector<int>>& matrix) {
    int left_col = 0;
    int right_col = matrix[0].size() - 1;

    while(left_col < right_col) {
        for(int row=0; row<matrix.size(); row++) {
            int temp = matrix[row][left_col];
            matrix[row][left_col] = matrix[row][right_col];
            matrix[row][right_col] = temp;
        }
        left_col++;
        right_col--;
    }
}

void rotate(vector<vector<int>>& matrix) {
    transpose(matrix);
    inverse(matrix);
}

int main() {

    return 0;
}
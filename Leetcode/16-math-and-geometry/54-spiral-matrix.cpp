/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    // cols
    int left = 0;
    int right = cols - 1;

    // rows
    int top = 0;
    int bottom = rows - 1;

    vector<int> result;

    while(left <= right && top <= bottom) {

        // left to right (changing columns)
        // top row
        for(int j=left; j<=right; j++) {
            result.push_back(matrix[top][j]);
        }
        top++;

        // top to bottom (changing rows)
        // right column
        for(int i=top; i<=bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;

        // right to left (changing columns)
        // bottom column
        if(top <= bottom) { // to prevent duplicates
            for(int j=right; j>=left; j--) {
                result.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        // bottom to top (changing rows)
        // left column
        if(left <= right) { // to prevent duplicates
            for(int i=bottom; i>=top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
        
    }        

    return result;
}

int main() {

    return 0;
}
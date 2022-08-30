/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int ctr = 1;

        // rows
        int top = 0;
        int bottom = n - 1;

        // cols
        int left = 0;
        int right = n - 1;

        while(top <= bottom && left <= right) {

            // filling top row
            for(int j=left; j<=right; j++) {
                matrix[top][j] = ctr;
                ctr++;
            } 
            top++;

            // filling right column
            for(int i=top; i<=bottom; i++) {
                matrix[i][right] = ctr;
                ctr++;
            }
            right--;

            // filling bottom row
            for(int j=right; j>=left; j--) {
                matrix[bottom][j] = ctr;
                ctr++;
            } 
            bottom--;

            // filling left column
            for(int i=bottom; i>=top; i--) {
                matrix[i][left] = ctr;
                ctr++;
            }
            left++;

        }

        return matrix;
    }
};
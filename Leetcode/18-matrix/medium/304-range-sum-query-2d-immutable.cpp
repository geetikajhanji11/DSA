/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NumMatrix {
    vector<vector<int>> prefixMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0; i<rows; i++) {
            vector<int> prefixRow;
            int sum = 0;
            int preRows = prefixMatrix.size();
            for(int j=0; j<cols; j++) {
                sum += matrix[i][j];
                int upperRow = preRows > 0 ? prefixMatrix[preRows-1][j] : 0;
                int ans = sum + upperRow; 
                prefixRow.push_back(ans);
            }
            prefixMatrix.push_back(prefixRow);
        } 
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        
        int biggerRetangle = prefixMatrix[row2][col2];
        int smallerRectangle1 = col1-1 >= 0 ? prefixMatrix[row2][col1-1] : 0;
        int smallerRectangle2 = row1-1 >= 0 ? prefixMatrix[row1-1][col2] : 0;
        int intersectedRectangle = row1-1 >= 0 && col1-1 >= 0 ? prefixMatrix[row1-1][col1-1] : 0;

        int sum = biggerRetangle - (smallerRectangle1 + smallerRectangle2 - intersectedRectangle);
        return sum;
    }
};
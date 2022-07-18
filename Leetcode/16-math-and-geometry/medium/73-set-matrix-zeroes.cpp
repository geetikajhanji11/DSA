#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    bool isFirstRowZero = false;
    bool isFirstColZero = false;
    
    for (int i = 0; i < m; i++) {
        if (matrix[i][0] == 0) {
            isFirstColZero = true;
            break;
        }
    }
    
    for (int j = 0; j < n; j++) {
        if (matrix[0][j] == 0) {
            isFirstRowZero = true;
            break;
        }
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }
    
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }
    
    if (isFirstColZero) {
        for (int i = 0; i < m; i++) {
            matrix[i][0] = 0;
        }
    }
    
    if (isFirstRowZero) {
        for (int j = 0; j < n; j++) {
            matrix[0][j] = 0;
        }
    }
}

int main() {

    return 0;
}
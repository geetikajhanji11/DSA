/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // start from the top right corner
        int i = 0;
        int j = cols - 1;
        while(i < rows && j >= 0) {
            if(target == matrix[i][j]) return true;
            else if(target < matrix[i][j]) j--;
            else if(target > matrix[i][j]) i++;
        }

        return false;
    }
};
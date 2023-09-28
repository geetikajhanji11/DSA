/*******************************************************************
Search for target value in matrix where every row & col is sorted

Perform 2 binary searches: 1 to find row, then another to find col

Time: O(log m + log n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // binary search in last column
        // smallest value that is bigger than target (get that row)
        int row_idx = -1;
        int last_col = cols - 1;
        
        int low = 0;
        int high = rows - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(matrix[mid][last_col] == target) return true;

            if(matrix[mid][last_col] < target) {
                low = mid + 1;
            } else {
                row_idx = mid;
                high = mid - 1;
            }
        }

        // couldn't find row
        if(row_idx == -1) return false;

        // normal binary search in found row
        low = 0;
        high = cols - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            if(matrix[row_idx][mid] == target) return true;

            if(matrix[row_idx][mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
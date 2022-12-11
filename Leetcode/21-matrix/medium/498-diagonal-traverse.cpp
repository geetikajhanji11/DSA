/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************ UP, DOWN SOLUTION ************
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> result;
        bool forward = true;

        // top row
        for(int col=0; col<cols; col++) {
            vector<int> currDiagonal;
    
            int i = 0;
            int j = col;
            while(i < rows && j >= 0) {
                currDiagonal.push_back(mat[i][j]);
                i++;
                j--;
            }

            if(forward) reverse(currDiagonal.begin(), currDiagonal.end());
            forward = !forward;
            result.insert(result.end(), currDiagonal.begin(), currDiagonal.end());
        }

        // last col
        for(int row=1; row<rows; row++) {
            vector<int> currDiagonal;
            
            int i = row;
            int j = cols - 1;
            while(i < rows && j >= 0) {
                currDiagonal.push_back(mat[i][j]);
                i++;
                j--;
            }

            if(forward) reverse(currDiagonal.begin(), currDiagonal.end());
            forward = !forward;
            result.insert(result.end(), currDiagonal.begin(), currDiagonal.end());
        }

        return result;

    }
};

// ************ MY SOLUTION ************
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        int rows = mat.size();
        int cols = mat[0].size();

        vector<int> result;
        bool forward = true;

        // top row
        for(int col=0; col<cols; col++) {
            vector<int> currDiagonal;
    
            int i = 0;
            int j = col;
            while(i < rows && j >= 0) {
                currDiagonal.push_back(mat[i][j]);
                i++;
                j--;
            }

            if(forward) reverse(currDiagonal.begin(), currDiagonal.end());
            forward = !forward;
            result.insert(result.end(), currDiagonal.begin(), currDiagonal.end());
        }

        // last col
        for(int row=1; row<rows; row++) {
            vector<int> currDiagonal;
            
            int i = row;
            int j = cols - 1;
            while(i < rows && j >= 0) {
                currDiagonal.push_back(mat[i][j]);
                i++;
                j--;
            }

            if(forward) reverse(currDiagonal.begin(), currDiagonal.end());
            forward = !forward;
            result.insert(result.end(), currDiagonal.begin(), currDiagonal.end());
        }

        return result;

    }
};
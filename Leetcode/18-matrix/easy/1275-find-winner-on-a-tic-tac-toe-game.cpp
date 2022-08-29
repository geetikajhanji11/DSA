/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool validLeftDiagonal(int row, int col, int player, vector<vector<int>> &grid) {
        int i = 0;
        int j = 0;
        for(i,j; i < 3 && j < 3; i++, j++) {
            if(grid[i][j] != player) return false;
        }
        return true;
    }

    bool validRightDiagonal(int row, int col, int player, vector<vector<int>> &grid) {
        int i = 0;
        int j = 2;
        for(i,j; i < 3 && j >= 0; i++, j--) {
            if(grid[i][j] != player) return false;
        }
        return true;
    }

    bool validRow(int row, int player, vector<vector<int>> &grid) {
        for(int j=0; j<3; j++) {
            if(grid[row][j] != player) return false;
        }
        return true;
    }

    bool validColumn(int col, int player, vector<vector<int>> &grid) {
        for(int i=0; i<3; i++) {
            if(grid[i][col] != player) return false;
        }
        return true;
    }

    bool isWinner(int row, int col, int player, vector<vector<int>> &grid) {
        if(validRow(row, player, grid) || validColumn(col, player, grid) ||
            validLeftDiagonal(row, col, player, grid) || validRightDiagonal(row, col, player, grid)) {
                return true;
            }
        return false;
    }

public:
    string tictactoe(vector<vector<int>>& moves) {
        // A => 1 [X] (plays first)
        // B => 0 [O]

        int n = 3;
        vector<vector<int>> grid(3, vector<int>(3, -1));

        int player = 1;

        int Amoves = 0;
        int Bmoves = 0;

        for(auto move : moves) {
            int i = move[0];
            int j = move[1];
            grid[i][j] = player;

            if(isWinner(i, j, player, grid)) {
                if(player == 1) return "A";
                return "B";
            }

            if(player == 1) {
                Amoves++;
                player = 0;
            } else {
                Bmoves++;
                player = 1;
            }
        }

        if(Amoves + Bmoves < 9) return "Pending";

        return "Draw";
    
    }
};
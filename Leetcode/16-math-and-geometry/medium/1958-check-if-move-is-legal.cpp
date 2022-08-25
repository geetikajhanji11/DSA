/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkMove(vector<vector<char>>& board, int rMove, int cMove, char color) {

        char altColor = 'W';
        if(color == 'W') altColor = 'B';

        int rows = board.size();
        int cols = board[0].size();

        int i, j;

        // check right
        j = cMove + 1;
        while(j < cols && board[rMove][j] == altColor) j++;
        if(j < cols && board[rMove][j] == color && j - cMove + 1 >= 3) return true;

        // check left
        j = cMove - 1;
        while(j >= 0 && board[rMove][j] == altColor) j--;
        if(j >= 0 && board[rMove][j] == color && cMove - j + 1 >= 3) return true;

        // check down
        i = rMove + 1;
        while(i < rows && board[i][cMove] == altColor) i++;
        if(i < rows && board[i][cMove] == color && i - rMove + 1 >= 3) return true;

        // check up
        i = rMove - 1;
        while(i >= 0 && board[i][cMove] == altColor) i--;
        if(i >= 0 && board[i][cMove] == color && rMove - i + 1 >= 3) return true;


        // check right up diagonal
        i = rMove - 1;
        j = cMove + 1;
        while(i >= 0 && j < cols && board[i][j] == altColor) {
            i--;
            j++;
        }
        if(i >= 0 && j < cols && board[i][j] == color && j - cMove + 1 >= 3) return true;


        // check right down diagonal
        i = rMove + 1;
        j = cMove + 1;
        while(i < rows && j < cols && board[i][j] == altColor) {
            i++;
            j++;
        }
        if(i < rows && j < cols && board[i][j] == color && j - cMove + 1 >= 3) return true;


        // check left up diagonal
        i = rMove - 1;
        j = cMove - 1;
        while(i >= 0 && j >= 0 && board[i][j] == altColor) {
            i--;
            j--;
        }
        if(i >= 0 && j >= 0 && board[i][j] == color && cMove - j + 1 >= 3) return true;

        
        // check left down diagonal
        i = rMove + 1;
        j = cMove - 1;
        while(i < rows && j >= 0 && board[i][j] == altColor) {
            i++;
            j--;
        }
        if(i < rows && j >= 0 && board[i][j] == color && cMove - j + 1 >= 3) return true;


        return false;
    }
};
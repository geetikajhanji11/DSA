/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> dx = {0, 0, -1, 1, 1, 1, -1, -1};
    vector<int> dy = {-1, 1, 0, 0, 1, -1, -1, 1};

    bool inBounds(int &i, int &j, vector<vector<int>>& board) {
        return i >= 0 && i < board.size() && j >= 0 && j < board[0].size();
    }

public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<pair<int, int>> flipIndexes;

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[0].size(); j++) {

                int dead_nbrs = 0;
                int alive_nbrs = 0;
                for(int k=0; k<8; k++) {
                    int next_i = i + dx[k];
                    int next_j = j + dy[k];
                    if(!inBounds(next_i, next_j, board)) continue;
                    if(board[next_i][next_j] == 1) alive_nbrs++;
                    else dead_nbrs++;
                }

                // alive
                if(board[i][j] == 1) {
                    if(alive_nbrs < 2 || alive_nbrs > 3) {
                        flipIndexes.push_back({i, j});
                    }                    
                }

                // dead
                else {
                    if(alive_nbrs == 3) {
                        flipIndexes.push_back({i, j});
                    }
                }
            }
        }

        for(auto idxPair : flipIndexes) {
            board[idxPair.first][idxPair.second] = !board[idxPair.first][idxPair.second];
        }
    }
};
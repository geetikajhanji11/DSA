/*******************************************************************

1,-1,-1,-1,-1
0, 1, -1,-1,-1
-1, 0, 1,-1,-1
 0, 1, 2,-1,-1
-1, 0, 1, 2, 3

if(col == 0 && mat[row][col] == -1) 
    => -1
if(col == cols-1 && mat[row][col] == 1) 
    => -1
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        // first fill in the answer for bottom row [dp]
        vector<int> dp(cols);
        for(int j=0; j<cols; j++) {

            int hole = -1;

            // the current cell is "\" and the next cell is "\"
            // pattern "\ \"
            if(j+1 < cols && grid[rows-1][j] == 1 && grid[rows-1][j+1] == 1) {
                hole = j + 1;
            }

            // the current cell is "/" and the next cell is "/"
            // pattern "/ /"
            else if(j-1 >= 0 && grid[rows-1][j] == -1 && grid[rows-1][j-1] == -1) {
                hole = j - 1;
            }

            dp[j] = hole; 
        }

        // for the upper rows 
        // going from bottom-1 row to top row
        for(int i=rows-2; i>=0; i--) {
            
            // going from left to right
            vector<int> next_dp(cols);
            for(int j=0; j<cols; j++) {
                int hole = -1;

                // the current cell is "\" and the next cell is "\"
                // pattern "\ \"
                if(j+1 < cols && grid[i][j] == 1 && grid[i][j+1] == 1) {
                    hole = dp[j+1];
                }

                // the current cell is "/" and the next cell is "/"
                // pattern "/ /"
                else if(j-1 >= 0 && grid[i][j] == -1 && grid[i][j-1] == -1) {
                    hole = dp[j-1];
                }

                next_dp[j] = hole;
            }

            dp = next_dp;
            
        }


        return dp;

    }
};
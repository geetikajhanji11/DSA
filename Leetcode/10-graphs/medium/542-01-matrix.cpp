/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

// ********************* DP *********************
// O(M.N) time and O(1) space
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        vector<vector<int>> distance(rows, vector<int>(cols, INT_MAX));

        // First pass: check for left and top
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(mat[i][j] == 0) {
                    distance[i][j] = 0;
                } else {
                    int left = j-1 >= 0 ? distance[i][j-1] : INT_MAX;
                    int top = i-1 >= 0 ? distance[i-1][j] : INT_MAX;
                    int val = min(left, top);
                    if(val != INT_MAX) {
                        val = val + 1;
                    }
                    distance[i][j] = min(distance[i][j], val); 
                }
            }
        }

        // Second pass: check for bottom and right
        for(int i=rows-1; i>=0; i--) {
            for(int j=cols-1; j>=0; j--) {
                if(mat[i][j] == 0) {
                    distance[i][j] = 0;
                } else {
                    int bottom = i+1 < rows ? distance[i+1][j] : INT_MAX;
                    int right = j+1 < cols ? distance[i][j+1] : INT_MAX;
                    int val = min(bottom, right);
                    if(val != INT_MAX) {
                        val = val + 1;
                    }
                    distance[i][j] = min(distance[i][j], val); 
                }
            }
        }

        return distance;
    }
};

// ********************* BREADTH FIRST SEARCH SOLUTION *********************
// O(M.N) time and O(M.N) space
class Solution {

    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    bool inBounds(int &i, int &j, vector<vector<int>>& mat) {
        return i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size();
    }

public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int rows = mat.size();
        int cols = mat[0].size();

        // 0 => i
        // 1 => j
        // 2 => distance from closest 0
        queue<vector<int>> q;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // push all positions of zero in the q
        // and mark them as visited
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }

        // do a simultaneous bfs for each node in queue
        while(!q.empty()) {

            int i = q.front()[0];
            int j = q.front()[1];
            int distance = q.front()[2];
            q.pop();

            for(int k=0; k<4; k++) {
                int next_i = i + dx[k];
                int next_j = j + dy[k];
                
                if(!inBounds(next_i, next_j, mat)) continue;
                if(visited[next_i][next_j]) continue;

                mat[next_i][next_j] = distance + 1;

                q.push({next_i, next_j, distance + 1});
                visited[next_i][next_j] = true;

            }

        }
        return mat;
    }
};
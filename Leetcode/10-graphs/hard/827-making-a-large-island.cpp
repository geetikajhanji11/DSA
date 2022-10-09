/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // 4-directions
    vector<int> dx = {0, 0, -1, 1};
    vector<int> dy = {-1, 1, 0, 0};

    // check if positionis in bounds
    bool inBounds(int i, int j, vector<vector<int>>& grid) {
        return i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size();
    }

    // dfs on island
    int exploreIsland(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &coordsToIslandId, int &islandId) {
        if(!inBounds(i, j, grid)) return 0;
        if(grid[i][j] == 0) return 0;

        // visited
        grid[i][j] = 0;
        coordsToIslandId[i][j] = islandId;

        // explore neighbours
        int size = 1;
        for(int k=0; k<4; k++) {
            int next_i = i + dx[k];
            int next_j = j + dy[k];
            size += exploreIsland(next_i, next_j, grid, coordsToIslandId, islandId);
        }

        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int rows = grid.size();
        int cols = grid[0].size();

        // data structures used
        vector<vector<int>> coordsToIslandId(rows, vector<int>(cols, -1));
        unordered_map<int, int> islandIdToSize;

        // explore every island initially 
        // give this island an ID and calculate its size as well
        // record this data in the maps
        vector<vector<int>> tempGrid = grid;
        int islandId = 0;
        int maxSize = 0;
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(tempGrid[i][j] == 1) {
                    int islandSize = exploreIsland(i, j, tempGrid, coordsToIslandId, islandId);
                    islandIdToSize[islandId] = islandSize;
                    maxSize = max(maxSize, islandSize);
                    islandId++;
                }
            }
        }

        // go over every 0 in the original grid
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {

                if(grid[i][j] == 0) {

                    // if we flip this 0 to 1,
                    // new island size will be + 1
                    int newIslandSize = 1;
                    unordered_set<int> nbrs;

                    // find all UNIQUE 4 directional nbrs for this 0
                    for(int k=0; k<4; k++) {
                        int next_i = i + dx[k];
                        int next_j = j + dy[k];
                        if(!inBounds(next_i, next_j, grid)) continue;
                        nbrs.insert(coordsToIslandId[next_i][next_j]);
                    }

                    // add their sizes to final island size
                    for(int nbr : nbrs) {
                        newIslandSize += islandIdToSize[nbr];
                    }

                    // update max size
                    maxSize = max(maxSize, newIslandSize);
                }
            }
        }

        return maxSize;
    }
};
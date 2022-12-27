/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // topological sort
    bool canBeErased(int colour, unordered_map<int, unordered_set<int>> &children, unordered_set<int> visited) {
        if(children[colour].empty()) return true;
        
        visited.insert(colour);

        for(int child : children[colour]) {
            if(visited.find(child) != visited.end()) return false;
            if(!canBeErased(child, children, visited)) return false;
        }

        visited.erase(colour);

        return true;
    }

public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows = targetGrid.size();
        int cols = targetGrid[0].size();

        unordered_map<int, int> topLeft_i;
        unordered_map<int, int> topLeft_j;

        unordered_map<int, int> bottomRight_i;
        unordered_map<int, int> bottomRight_j;

        unordered_set<int> coloursSeen;

        // find the topLeft and bottomRight coords of each colour
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                int colour = targetGrid[i][j];

                // not yet seen this colour
                if(coloursSeen.find(colour) == coloursSeen.end()) {
                    topLeft_i[colour] = i;
                    topLeft_j[colour] = j;

                    bottomRight_i[colour] = i;
                    bottomRight_j[colour] = j;
                    
                    coloursSeen.insert(colour);
                } else {
                    topLeft_i[colour] = min(topLeft_i[colour], i);
                    topLeft_j[colour] = min(topLeft_j[colour], j);

                    bottomRight_i[colour] = max(bottomRight_i[colour], i);
                    bottomRight_j[colour] = max(bottomRight_j[colour], j);

                    
                }

            }
        }


        unordered_map<int, unordered_set<int>> children;

        // for each unique colour
        for(int colour : coloursSeen) {

            int i1 = topLeft_i[colour];
            int j1 = topLeft_j[colour];

            int i2 = bottomRight_i[colour];
            int j2 = bottomRight_j[colour];

            bool foundOtherColour = false;

            // for every colour's rectangular area, 
            // search if any other colour exists
            for(int i=i1; i<=i2; i++) {
                for(int j=j1; j<=j2; j++) {

                    // if exists, then for current colour to be cleared,
                    // the child should be cleared first
                    if(targetGrid[i][j] != colour) {
                        children[colour].insert(targetGrid[i][j]);
                        foundOtherColour = true;
                    }
                }
            }

            if(!foundOtherColour) {
                children[colour] = {};
            }

        }

        // apply topological search on every colour
        for(int colour : coloursSeen) {
            if(!canBeErased(colour, children, {})) return false;
            children[colour].clear();
        }

        return true;
    }
};
/*******************************************************************
// -1 => not colourd
// 0 => partition 1
// 1 => partition 2
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // returns true if it is valid to colour the node as given color
    bool isValid(int node, vector<vector<int>>& graph, vector<int> &colorOf, int color) {
        
        // node has already been coloured
        // check if its colour is same as the parameter "color"
        if(colorOf[node] != -1) {
            return colorOf[node] == color;
        }

        // colour the node
        colorOf[node] = color;

        // colour all the other neighbours as the 
        // alternate colour
        for(int nbr : graph[node]) {
            int altColour = colorOf[node] == 0 ? 1 : 0;
            if(!isValid(nbr, graph, colorOf, altColour)) return false;
        }

        return true;
    }

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colorOf(n, -1);

        // check validity of every node that has not been 
        // coloured yet
        for(int node=0; node<n; node++) {
            if(colorOf[node] == -1 && !isValid(node, graph, colorOf, 0)) {
                return false;
            }
        }

        // all nodes are corretly coloured
        return true;

    }
};
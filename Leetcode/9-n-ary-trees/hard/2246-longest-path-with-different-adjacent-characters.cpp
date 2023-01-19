/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {

    int longestPathLength(int node, vector<vector<int>> &children, string &s, int &maxPath) {
        
        // find max 2 longest paths for current node's children 
        int l1 = 0; // 1st max (val is 0 => no child with diff adj char found)
        int l2 = 0; // 2nd max (val is 0 => no 2nd child with diff adj char found)

        // go over every child
        for(int child : children[node]) {
            int pathLength = longestPathLength(child, children, s, maxPath);
        
            if(s[child] != s[node] && pathLength > l1) {
                l2 = l1;
                l1 = pathLength;
            } else if(s[child] != s[node] && pathLength > l2) {
                l2 = pathLength;
            }
        }

        // joining two max children's lengths
        // if two max length children exist
        if(l2 != 0) maxPath = max(maxPath, 1 + l1 + l2);

        // initially curr length is 1 (node itself)
        int currPathLength = 1;
        if(l1 != 0) currPathLength += l1;  // if largest length child exists, add its length
        maxPath = max(maxPath, currPathLength);

        // return curr node's path length
        return currPathLength;
    }

public:
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        
        vector<vector<int>> children(n);

        for(int node=1; node<n; node++) {
            children[parent[node]].push_back(node);
        }

        int maxPath = 0;
        longestPathLength(0, children, s, maxPath);

        return maxPath;
    }
};
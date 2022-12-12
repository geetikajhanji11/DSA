/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// **************** MY SOLUTION ****************
class Solution {

    int findUltimateParent(int node, vector<int> &parent) {
        if(parent[node] == -1) return node;
        return findUltimateParent(parent[node], parent);
    }

public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> parent(n, -1);

        for(int node=0; node<n; node++) {

            int ultimateParent = findUltimateParent(node, parent);

            if(leftChild[node] != -1) {
                if(parent[leftChild[node]] != -1) return false;
                if(ultimateParent == leftChild[node]) return false;
                parent[leftChild[node]] = node;
            }

            if(rightChild[node] != -1) {
                if(parent[rightChild[node]] != -1) return false;
                if(ultimateParent == rightChild[node]) return false;
                parent[rightChild[node]] = node;
            }

        }

        int negOnes = 0;
        for(int p : parent) {
            if(p == -1) negOnes++;
        }

        return negOnes == 1;
    }
};
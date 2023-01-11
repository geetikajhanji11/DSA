/*******************************************************************
cout<<"half = "<<half<<endl;

cout<<i1<<", "<<j1<<endl;
cout<<x1<<", "<<x2<<endl<<endl;

cout<<i1<<", "<<x4<<endl;
cout<<x1<<", "<<j2<<endl<<endl;

cout<<x3<<", "<<j1<<endl;
cout<<i2<<", "<<x2<<endl<<endl;

cout<<x3<<", "<<x4<<endl;
cout<<i2<<", "<<j2<<endl<<endl;
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};


class Solution {

    Node* divide(int i1, int j1, int i2, int j2, vector<vector<int>>& grid) {

        // one cell => leaf node
        if(i1 == i2 && j1 == j2) {
            int val = grid[i1][j1];
            bool isLeaf = true;
            return new Node(val, isLeaf);
        }

        // traverse this currend grid [i1, j1, i2, j2]
        // if all values of it are same, it is a leafNode
        int val = grid[i1][j1];
        bool isLeaf = true;
        for(int i=i1; i<=i2; i++) {
            for(int j=j1; j<=j2; j++) {
                if(grid[i][j] != val) {
                    isLeaf = false;
                    break;
                }
            }
        }

        // it is a leaf node
        if(isLeaf) {
            return new Node(val, isLeaf);
        }

        // it is not a leaf node
        val = 1;
        int half = ((i2 - i1) + 1) / 2;
        int rowMid = i1 + half;
        int colMid = j1 + half;

        // traverse in Z manner
        Node* topLeft = divide(i1, j1, rowMid-1, colMid-1, grid);
        Node* topRight = divide(i1, colMid, rowMid-1, j2, grid);
        Node* bottomLeft = divide(rowMid, j1, i2, colMid-1, grid);
        Node* bottomRight = divide(rowMid, colMid, i2, j2, grid);

        Node* root = new Node(val, isLeaf, topLeft, topRight, bottomLeft, bottomRight);
        return root;
    }

public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return divide(0, 0, n-1, n-1, grid);
    }
};
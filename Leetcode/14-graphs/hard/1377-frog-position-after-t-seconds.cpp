/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class QueueNode {
public:
    int val;
    double probability;
    int timeLeft;

    QueueNode(int node, double p, int t) {
        this->val = node;
        this->probability = p;
        this->timeLeft = t;
    }
};

class Solution {

    // returns the number of children of current node
    // since children[node] can also contain parent 
    // due to undirected link 
    int getChildrenCount(QueueNode &node, vector<vector<int>> &children, vector<bool> &visited) {
        int childrenCount = 0;
        for(int child : children[node.val]) {
            if(visited[child]) continue;
            childrenCount++;
        } 
        return childrenCount;
    }

public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        
        // nodes [1,....,n]
        // 1 based indexing
        vector<vector<int>> children(n+1);

        // create undirected graph
        for(auto edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        // BFS
        queue<QueueNode> q;
        vector<bool> visited(n+1, false);
        
        // insert node "1" since it is overall root
        q.push(QueueNode(1, 1.0, t));
        visited[1] = true;

        // traverse until queue is empty
        while(!q.empty()) {
            QueueNode node = q.front(); q.pop();

            if(node.val == target && node.timeLeft == 0) return node.probability;
            if(node.timeLeft == 0) continue;

            int childrenCount = getChildrenCount(node, children, visited);

            if(node.val == target) {
                if(childrenCount == 0 && node.timeLeft > 0) return node.probability;
                return 0.0;
            }

            double nextProbability = 1.0 / (double) childrenCount;
    
            for(int child : children[node.val]) {
                if(visited[child]) continue;
                q.push(QueueNode(child, node.probability * nextProbability, node.timeLeft - 1));
                visited[child] = true;
            } 

        }

        return 0;
    }
};
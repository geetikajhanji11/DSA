/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************ USING SAME FREQUENCY ARRAY EVERY TIME ************
class Solution {

    void updateFrequecy(int node, vector<vector<int>> &children, vector<bool> &visited, string &labels, vector<int> &frequency, vector<int> &result, int &n) {
        visited[node] = true;

        // frequency of "labels[node]" for all the nodes
        // that are at the top of the current node
        int topNodesFrequency = frequency[labels[node] - 'a'];

        // for current node
        frequency[labels[node] - 'a'] += 1;

        // adding frequency of "labels[node]" for all the nodes
        // that are at the bottom of the current node
        for(int child : children[node]) {
            if(visited[child]) continue;
            updateFrequecy(child, children, visited, labels, frequency, result, n);
        }

        // to get children nodes for current label,
        // subtract topNodesFrequency from overall frequency
        // calculated up until now
        result[node] = frequency[labels[node] - 'a'] - topNodesFrequency;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>> children(n);

        for(auto edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        vector<int> frequency(26, 0);
        vector<int> result(n, 0);
        
        updateFrequecy(0, children, visited, labels, frequency, result, n);
        
        return result;
    }
};

// ************ RETURNING NEW FREQUENCY ARRAY EVERY TIME ************
class Solution {

    vector<int> subtreeFrequecy(int node, vector<vector<int>> &children, vector<bool> &visited, string &labels, vector<int> &result, int &n) {
        visited[node] = true;

        vector<int> frequency(26, 0); // a-z
        for(int child : children[node]) {
            if(visited[child]) continue;
            vector<int> childFrequency = subtreeFrequecy(child, children, visited, labels, result, n);
            for(int i=0; i<26; i++) {
                frequency[i] += childFrequency[i];
            }
        }

        frequency[labels[node] - 'a']++;
        result[node] = frequency[labels[node] - 'a'];

        return frequency;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<vector<int>> children(n);

        for(auto edge : edges) {
            children[edge[0]].push_back(edge[1]);
            children[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        vector<int> result(n, 0);

        subtreeFrequecy(0, children, visited, labels, result, n);
        
        return result;
    }
};
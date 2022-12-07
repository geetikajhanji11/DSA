/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        vector<int> arr;
        arr.push_back(0);

        // converting board to 1d array
        int k=0;
        for(int i=n-1; i>=0; i--){
            if(k%2 == 0){
                for(int j=0; j<n; j++){
                    arr.push_back(board[i][j]);
                }
            } else {
                for(int j=n-1;j>=0;j--){
                    arr.push_back(board[i][j]);
                }
            }
            k++;
        }
        
        // BFS
        queue<int> q;
        int distance = 1;
        vector<bool> visited(n*n + 1, false);

        q.push(1);
        visited[1] = true;
        
        while(!q.empty()) {
            int size = q.size();
            
            for(int i=0; i<size; i++) {
                int curr = q.front(); q.pop();

                if(curr == n*n) return distance;
                
                for(int dice=1; dice<=6; dice++){
                    int nxt = curr + dice;
                    if(arr[nxt] != -1) {
                        nxt = arr[nxt];
                    }
                        
                    if(nxt == n*n) return distance;
                    if(visited[nxt]) continue;

                    visited[nxt] = true;
                    q.push(nxt);
                }
            }

            distance++;
        }

        return -1;
    }
};



// *************************************************
// wrong answer due to faulty logic
// *****************************************

class Graph {

    int V;
    list<int> *adjList;

public:

    Graph(int v) {
        this->V = v;
        adjList = new list<int>[V];
    }

    // directed 
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    int shortestPathBFS(int source, int destination) {
        queue<int> q; // vertex, distance
        vector<bool> visited(V, false);
        
        q.push(source);
        visited[source] = true;

        int distance = 1;

        while(!q.empty()) {

            int size = q.size();

            for(int i=0; i<size; i++) {
                int node = q.front(); q.pop();

                if(node == destination) return distance;

                for(int nbr : adjList[node]) {
                    if(visited[nbr]) continue;

                    if(nbr == destination) return distance;

                    q.push(nbr);
                    visited[nbr] = true;
                }
            }

            distance++;

        }   

        return -1;
    }

};

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        
        int n = board.size();

        unordered_map<int, int> m;

        int cell = 1;
        for(int row=n-1; row>=0; row--) {
            for(int col=0; col<n; col++) {
                if(board[row][col] != -1) {
                    m[cell] = board[row][col];
                }
                cell++;
            }
        }

        Graph g(n*n + 1);

        for(int u=1; u<n*n; u++) {
            for(int dice=1; dice<=6; dice++) {
                int v = u + dice;
                if(m.find(v) != m.end()) {
                    v = m[v];
                }
                g.addEdge(u, v);
            }
        }

        return g.shortestPathBFS(1, n*n);
    }
};
/*******************************************************************
SNAKES AND LADDERS

Given a Snakes and Ladder board of size N, which contains multiple
Snakes and Ladders. You are also given starting and ending point
of each snake and ladder in vector<pair<int, int>>. As per the rules:

    1.  If you are bitten by snake, you will reach the position
        where tail of snake ends.
    
    2.  If you reach a cell having starting point of ladder, you
        will climb the ladder.

Compute the minimum number of dice throws needed to reach the end of 
the game starting from cell 1. In each turn you can throw any number
from 1 - 6 on the dice to move ahead in the board.

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *adjList;

    public:

    Graph(int v) {
        this->V = v;
        this->adjList = new list<int>[V+1];
    }

    // directed graph
    void addEdge(int from, int to) {
        adjList[from].push_back(to);
    }

    // bfs shortest path
    int shortestPathBFS(int source, int destination) {
        vector<bool> visited(V, false);
        vector<int> distance(V, 0);
        queue<int> Q;

        Q.push(source);
        visited[source] = true;
        distance[source] = 0;

        while(!Q.empty()) {
            int curr_vertex = Q.front();
            Q.pop();
            for(int nbr : adjList[curr_vertex]) {
                if(!visited[nbr]) {
                    Q.push(nbr);
                    visited[nbr] = true;
                    distance[nbr] = distance[curr_vertex] + 1;
                }
                
            }
        }
        return distance[destination];
    }
};

int min_dice_throws(int n,vector<pair<int,int> > snakes, vector<pair<int,int> > ladders){
    vector<int> board(n+1, 0);

    for(auto snake : snakes) {
        int start = snake.first;
        int end = snake.second;
        board[start] = end - start; 
    }   

    for(auto ladder : ladders) {
        int start = ladder.first;
        int end = ladder.second;
        board[start] = end - start;
    }

    Graph g(n+1);
    for(int u=1; u<n; u++) {
        for(int dice=1; dice<=6; dice++) {
            int v = u + dice;
            v += board[v];
            if(v <= n) {
                g.addEdge(u, v);
            }
        }
    }

    int result = g.shortestPathBFS(1, n);
    return result;
}

int main() {

    return 0;
}
/*******************************************************************
KOSARAJU’s Algorithm
*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

class Graph {

    int V;
    list<int> *adjList;

    // directed graph
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    } 

    
public:
    
    // constructor
    Graph(int V, vector<vector<int>>& edges) {
        this->V = V;
        this->adjList = new list<int>[V];
        for(auto edge : edges) {
            addEdge(edge[0], edge[1]);
        }
    }

    // step - 1  
    // TOPOLOGICAL SORT
    void dfs(int node, vector<int> &visited, vector<int> &sortedNodes) {
        visited[node] = true;
        for(int nbr : adjList[node]) {
            if(visited[nbr]) continue;
            dfs(nbr, visited, sortedNodes);
        }
        sortedNodes.push_back(node);
    }

    vector<int> topologicalSortedNodes() {
        vector<int> visited(V, false);
        vector<int> sortedNodes;
        for(int node=0; node<V; node++) {
            if(visited[node]) continue;
            dfs(node, visited, sortedNodes);
        }
        reverse(sortedNodes.begin(), sortedNodes.end());
        return sortedNodes;
    }

    // step - 2
    // TRANSPOSE GRAPH
    list<int>* getTransposedGraph() {
        list<int> *transposedAdjList = new list<int>[V];
        for(int node=0; node<V; node++) {
            for(int nbr : adjList[node]) {
                transposedAdjList[nbr].push_back(node);
            }
        }
        return transposedAdjList;
    }

    // step - 3
    // DFS according to finishing time (from topologicalSort)
    void dfs(int node, vector<bool> &visited, list<int> *transposedAdjList, vector<int> &SCC) {
        visited[node] = true;

        for(int nbr : transposedAdjList[node]) {
            if(!visited[nbr]) {
                dfs(nbr, visited, transposedAdjList, SCC);
            }
        }

        SCC.push_back(node);

    }

    // KOSARAJU ALGORITHM
    vector<vector<int>> getSCCs() {

        // step - 1
        vector<int> sortedNodes = topologicalSortedNodes();

        // step - 2
        list<int> *transposedAdjList = getTransposedGraph();
        cout<<"\nTransposed";

        // step - 3
        vector<vector<int>> SCCs;
        vector<bool> visited(V, false);
        for(int node : sortedNodes) {
            if(!visited[node]) {
                vector<int> SCC;
                dfs(node, visited, transposedAdjList, SCC);
                SCCs.push_back(SCC);
            }
        }

        return SCCs;
    }

};


int main() {
    
    int V = 7;
    vector<vector<int>> edges = {{0,1},{1,2},{1,3},{3,4},{4,0},{4,5},{4,6},{5,6},{6,5}};
    
    Graph g(V, edges);
    auto SCCs = g.getSCCs();

    cout<<"\nSCCs:\n";
    for(auto SCC : SCCs) {
        for(int node : SCC) {
            cout<<node<<", ";
        }
        cout<<endl;
    }
	
	return 0;
}
/*******************************************************************
Tarjan’s Algorithm
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

    // dfs for Tarjan’s Algorithm
    void dfs(int node, int &time, vector<bool> &visited, vector<int> &discoveryTime, vector<int> &low, stack<int> &nodeStack, vector<bool> &inStack, vector<vector<int>> &SCCs) {

        // mark the current node as visited
        visited[node] = true;

        // and push in stack
        nodeStack.push(node);
        inStack[node] = true;

        // set the discovery time and low time 
        // as current time
        discoveryTime[node] = time;
        low[node] = time;
        time++;

        // iterate over every child
        for(int child : adjList[node]) {

            // child was not visited, visit it
            if(!visited[child]) {
                dfs(child, time, visited, discoveryTime, low, nodeStack, inStack, SCCs);
                low[node] = min(low[node], low[child]);
            } 
            
            // differentiate between back/cross edge
            else {

                // back edge
                if(inStack[child]) {    
                    low[node] = min(low[node], discoveryTime[child]);
                } 

                // cross edge
                // do nothing
                else {}
            }
        }

        // if node is the head node of SCC
        // pop from stack until head node is reached
        if(low[node] == discoveryTime[node]) {
            vector<int> SCC;
            while(nodeStack.top() != node) {
                int otherNode = nodeStack.top();
                nodeStack.pop();

                SCC.push_back(otherNode);
                inStack[otherNode] = false;
            }

            // pop head node
            nodeStack.pop();
            SCC.push_back(node);
            inStack[node] = false;

            // push SCC into SCCs
            SCCs.push_back(SCC);
        }
        
    }

    // Tarjan’s Algorithm
    vector<vector<int>> getSCCs() {

        int time = 0;
        vector<bool> visited(V, false);
        vector<int> discoveryTime(V, 0);
        vector<int> low(V, 0);
        vector<vector<int>> SCCs;
        stack<int> nodeStack;
        vector<bool> inStack(V, false);

        for(int node=0; node<V; node++) {
            if(!visited[node]) {
                dfs(node, time, visited, discoveryTime, low, nodeStack, inStack, SCCs);
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
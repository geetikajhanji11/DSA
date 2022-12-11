/*******************************************************************
(Also check DFS Solution)

WALKTHROUGH OF ALGORITHM

ADJACENCY LIST
--------------

    (a, 1)  :   [(b, 1.5)]
    (b, 1)  :   [(a, 0.666667), (c, 2.5)]
    (c, 1)  :   [(b, 0.4)]
    (bc, 1) :   [(cd, 5)]
    (cd, 1) :   [(bc, 0.2)]


for (a, c)
----------

    QUEUE = [a, b, c]

    (a, 1)  :   [(b, 1.5)]
    (b, 1.5)  :   [(a, 0.666667), (c, 2.5)]
    (c, 3.75)  :   [(b, 0.4)]  => {1.5 * 2.5 = 3.75}
    (bc, 1) :   [(cd, 5)]
    (cd, 1) :   [(bc, 0.2)]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    class Node {
    public:
        string name;
        double val;
        vector<pair<string, double>> neighbours;
        Node() {}
        Node(string name, double val) {
            this->name = name;
            this->val = val;
            this->neighbours = {};
        }
    };

    double shortestPathBFS(string source, string destination, unordered_map<string, Node> adjList) {
       
        // either source or destination does not exist
        if(adjList.find(source) == adjList.end()) return -1.0;
        if(adjList.find(destination) == adjList.end()) return -1.0;

        // source and destination are same
        if(source == destination) return 1.0;

        queue<string> q;
        unordered_set<string> visited;

        q.push(source);
        visited.insert(source);

        // bfs
        while(!q.empty()) {

            string curr = q.front();
            if(curr == destination) {
                return adjList[curr].val;
            }
            q.pop();

            for(auto nbr : adjList[curr].neighbours) {

                string nbrName = nbr.first;
                double edgeVal = nbr.second;

                // already visited, skip
                if(visited.find(nbrName) != visited.end()) continue;

                visited.insert(nbrName);
                adjList[nbrName].val = adjList[curr].val * edgeVal ;
                q.push(nbrName);
                
            }
        }
        
        // could not find a path from
        // source => destination
        return -1.0;
    }


public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // creating the adjacency list
        unordered_map<string, Node> adjList;
        for(int i=0; i<equations.size(); i++) {
            double val = values[i];
            string a = equations[i][0];
            string b = equations[i][1];

            if(adjList.find(a) == adjList.end()) {
                Node newNode(a, 1.0);
                adjList[a] = newNode;
            }

            if(adjList.find(b) == adjList.end()) {
                Node newNode(b, 1.0);
                adjList[b] = newNode;
            }

            adjList[a].neighbours.push_back({b, val});
            adjList[b].neighbours.push_back({a, 1.0 / val});

        }

        // calling shorted path bfs for each query
        vector<double> result; 
        for(auto query : queries) {
            double ans = shortestPathBFS(query[0], query[1], adjList);
            result.push_back(ans);
        }
        
        return result;

    }
};

int main() {

    Solution s;
    vector<vector<string>> equations = {{"a","b"},{"b","c"},{"bc","cd"}};
    vector<double> values = {1.5,2.5,5.0};
    vector<vector<string>> queries = {{"a","c"},{"c","b"},{"bc","cd"},{"cd","bc"}, {"x", "x"}, {"a", "a"}};
    s.calcEquation(equations, values, queries);
    return 0;
}
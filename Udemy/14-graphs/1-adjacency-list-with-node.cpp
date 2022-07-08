#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    string name;
    list<string> nbrs;

    Node(string name) {
        this->name = name;
    }
};

class Graph {
    
    unordered_map<string, Node*> adjList;

    public:

    // constructor
    Graph(vector<string> names) {
        for(string name : names) {
            adjList[name] = new Node(name);
        }
    }

    // add a new edge
    void addEdge(string x, string y, bool undirected = true) {
        Node *x_node = adjList[x];
        Node *y_node = adjList[y];
        x_node->nbrs.push_back(y);
        if(undirected) {
            y_node->nbrs.push_back(x);
        }
    } 

    // print the adjacency list
    void printAdjList() {
        for(auto element : adjList) {
            string city = element.first;
            Node *city_node = element.second;
            cout<<endl<<city<<" ---> ";
            for(auto nbr : city_node->nbrs) {
                cout<<nbr<<", ";
            }
        }
    }

};

int main() {
    
    vector<string> cities = {"Delhi", "London", "Paris", "New York"};
    Graph g(cities);
    g.addEdge("Delhi", "London");
    g.addEdge("New York", "London");
    g.addEdge("Delhi", "Paris");
    g.addEdge("Paris", "New York");

    g.printAdjList();
    return 0;
}
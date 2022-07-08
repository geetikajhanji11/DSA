/*******************************************************************
 * ASTRONAUT PAIR
 * 
 * 
 * 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Graph {
    int V;
    list<int> *adjList;

    public:

    // constructor
    Graph(int v) {
        this->V = v;
        adjList = new list<int>[V];
    }

    // add a new edge
    void addEdge(int i, int j) {
        adjList[i].push_back(j);
        adjList[j].push_back(i);
    } 

    // print the adjacency list
    void printAdjList() {
        for(int i=0; i<V; i++) {
            cout<<"\nVertex "<<i<<" => ";
            for(int j : adjList[i]) {
                cout<<j<<", ";
            }
        }
    }

    // breadth first search (FIFO)
    // FOR DISCONNECTED GRAPH
    vector<int> bfs(int n) {

        // data structures
        vector<int> graph_sizes;
        vector<bool> visited(V, false);
        queue<int> Q;

        // for each vertex
        for(int i=0; i<n; i++) {
            
            int source = i;

            // size counter for each
            // disconnected graph
            int ctr = 0;
            
            // if this node has already
            // been visited, do not explore
            if(visited[source]) continue;

            cout<<"\nSOURCE = "<<source<<" => ";

            Q.push(source);
            visited[source] = true;

            while(!Q.empty()) {

                int curr_vertex = Q.front();
                cout<<curr_vertex<<", ";
                ctr++; // increment
                
                list<int> nbrs = adjList[curr_vertex];
                for(int nbr : nbrs) {
                    if(!visited[nbr]) {
                        Q.push(nbr);
                        visited[nbr] = true;
                    }
                }
                Q.pop();
            }
            graph_sizes.push_back(ctr);
        }

        return graph_sizes;
    }

};

int count_pairs(int N, vector<pair<int,int> > astronauts){
    //complete this method
    
    
    Graph g(N);
    for(auto p : astronauts) {
        g.addEdge(p.first, p.second);
    }

    vector<int> sizes = g.bfs(N);
    cout<<"\nNUMBER OF NODES IN EACH DISCONNECTED GRAPH\n";
    for(int size : sizes) {
        cout<<size<<endl;
    }

    int result = 0;
    for(int i=0; i<sizes.size(); i++) {
        for(int j=i+1; j<sizes.size(); j++) {
            result += sizes[i] * sizes[j];  
        }
    }

    return result;
}

int main() {

    int N = 5;
    vector<pair<int,int> > astronauts = {
        {0, 1},
        {0, 4},
        {3, 2},
        // {5, 6}
    };
    int result = count_pairs(N, astronauts);
    cout<<"\nRESULT = "<<result;
    return 0;
}

/* PRATEEK SOLUTION

#include<list>
#include<queue>
using namespace std;

class Graph{
	list<int> *l;
	int V;
public:
	Graph(int v){
		V = v;
		//Array of Linked List
		l = new list<int>[V];
	}

	void addEdge(int i,int j,bool bidir=true){
		l[i].push_back(j);
		if(bidir){
			l[j].push_back(i);
		}
	}
	int traverseHelper(int s,bool *visited){
		visited[s] = true;
		int size = 1;

		//visit the neighbours of s and thier neighbours recursilvely
		for(int nbr:l[s]){
			if(!visited[nbr]){
				size += traverseHelper(nbr,visited);
			}
		}
		return size;
	}
	//DFS - Depth First Search O(V+E) Linear
	int countAstronauts(){
		bool *visited = new bool[V]{0};
		int ans = V*(V-1)/2;

		for(int i=0;i<V;i++){
			if(!visited[i]){

				
				 int csize = traverseHelper(i,visited);
				 ans -= (csize)*(csize-1)/2;
				 
			}
		}
		return ans;
	}

};

int count_pairs(int N, vector<pair<int,int> > astronauts){
    //complete this method
    Graph g(N);
    
    for(auto edge : astronauts){
        g.addEdge(edge.first,edge.second);
    }
    
    return g.countAstronauts();
}


© 2022 GitHub, Inc.
Terms
P
*/
/*******************************************************************
Given airline tickets, find valid itinerary (use all tickets once)
Ex. tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
    output = ["JFK","MUC","LHR","SFO","SJC"]

Greedy DFS, build route backwards when retreating, merge cycles 
into main path

Time: O(E log (E / V)) -> E = # of flights, V = # of airports, sorting
Space: O(V + E) -> store # of airports & # of flights in hash map

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> m;
        for (int i = 0; i < tickets.size(); i++) {
            m[tickets[i][0]].insert(tickets[i][1]);
        }
        
        vector<string> result;
        dfs(m, "JFK", result);
        reverse(result.begin(), result.end());
        return result;
    }
private:
    void dfs(unordered_map<string, multiset<string>>& m,
        string airport, vector<string>& result) {
        
        while (!m[airport].empty()) {
            string next = *m[airport].begin();
            m[airport].erase(m[airport].begin());
            dfs(m, next, result);
        }
        
        result.push_back(airport);
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool can_visit(string source, unordered_map<string, vector<string>> adj_list, vector<string> &result, int &edges) {
    
    if(result.size() == edges + 1) return true; // reached end of path
    if(adj_list[source].empty()) return false; // path is not complete and no other nbr to visit

    vector<string> temp_nbrs = adj_list[source];
    for(int i=0; i<temp_nbrs.size(); i++) {

        // visiting the nbr
        // this means erasing it from the adj_list
        // and including it in our path
        string nbr = temp_nbrs[i];
        adj_list[source].erase(adj_list[source].begin() + i);
        result.push_back(nbr);

        // dfs on that nbr
        if(can_visit(nbr, adj_list, result, edges)) return true;
        
        // if path does not exist from this nbr, (BACKTRACKING)
        // insert it back into the adj_list at the same pos, 
        // so it can be visited later and remove from path
        adj_list[source].insert(adj_list[source].begin() + i, nbr);
        result.pop_back();
    }

    // we reached here, 
    // it means we cannot complete path
    // from this source
    return false;

}

struct compare_fn {
    bool operator() (vector<string> &t1, vector<string> &t2) {
        return t1[1] < t2[1];
    }
};

vector<string> findItinerary(vector<vector<string>>& tickets) {

    int edges = tickets.size();

    // sort the tickets vector so that
    // the adjlist itself is sorted later
    sort(tickets.begin(), tickets.end(), compare_fn());
    
    // create adjacency list
    // airport1 => list of airports in lexical order
    unordered_map<string, vector<string>> adj_list;
    for(auto ticket : tickets) {
        string from = ticket[0];
        string to = ticket[1];
        adj_list[from].push_back(to);
    }

    // result vector
    vector<string> result;
    result.push_back("JFK");

    // perform dfs from JFK
    can_visit("JFK", adj_list, result, edges);
    
    return result;
}

int main() {

    vector<vector<string>> tickets = {
        {"JFK","SFO"},
        {"JFK","ATL"},
        {"SFO","ATL"},
        {"ATL","JFK"},
        {"ATL","SFO"}
    };

    auto res = findItinerary(tickets);
    for(string s : res) cout<<s<<", ";
    return 0;
}
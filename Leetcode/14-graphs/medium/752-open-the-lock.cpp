/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<string> getChildren(string curr) {

        vector<string> children;

        for(int i=0; i<4; i++) {

            string nbr = curr;
            int val = curr[i] - '0';

            // increment and push
            int incrementedVal = (val + 1) % 10;
            nbr[i] = to_string(incrementedVal)[0];
            children.push_back(nbr);

            // decrement and push
            int decrementedval = ((val - 1) + 10) % 10;
            nbr[i] = to_string(decrementedval)[0];
            children.push_back(nbr);
        }

        return children;
    }

public:
    int openLock(vector<string>& deadends, string target) {
        
        // converting deadends into a set
        unordered_set<string> deadendSet;
        for(string deadend : deadends) {
            deadendSet.insert(deadend);
            if(deadend == target) return -1;
            if(deadend == "0000") return -1;
        }

        // bfs
        queue<pair<string, int>> q;
        unordered_set<string> visited = deadendSet;

        // pair => {curr state, moves}
        q.push({"0000", 0});
        visited.insert("0000");

        while(!q.empty()) {

            auto p = q.front(); q.pop();
            string curr = p.first;
            int moves = p.second;
            if(curr == target) return moves;

            // pushing all future combinations
            vector<string> children = getChildren(curr);
            for(string child : children) {
                if(visited.find(child) == visited.end()) {
                    visited.insert(child);
                    q.push({child, moves + 1});
                }
            }
            
        }
        
        return -1;

    }
};
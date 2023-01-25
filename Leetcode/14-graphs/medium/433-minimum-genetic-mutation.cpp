/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isValidMutation(string const &gene1, string &gene2) {
        bool oneCharDiff = false;
        for(int i=0; i<8; i++) {
            if(gene1[i] != gene2[i]) {
                if(oneCharDiff) return false;
                oneCharDiff = true;
            }
        }
        return true;
    }

public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_map<string, vector<string>> m;

        // ********* CREATE MAP *********
        m[startGene] = {};
        for(string gene : bank) {
            for(auto kv : m) {
                if(isValidMutation(kv.first, gene)) {
                    m[kv.first].push_back(gene);
                    m[gene].push_back(kv.first);
                }
            }
        }

        // ********* BFS *********
        queue<pair<string, int>> q;
        q.push({startGene, 0});
        unordered_set<string> visited;
        visited.insert(startGene);

        while(!q.empty()) {
            string currGene = q.front().first;
            int length = q.front().second;
            q.pop();

            if(currGene == endGene) return length;

            for(string nbrGene : m[currGene]) {
                if(visited.find(nbrGene) != visited.end()) continue;

                q.push({nbrGene, length + 1});
                visited.insert(nbrGene);
            }
        }

        return -1;
    }
};
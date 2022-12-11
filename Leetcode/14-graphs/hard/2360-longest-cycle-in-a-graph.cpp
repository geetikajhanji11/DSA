/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();

        int maxLength = -1;
        vector<bool> visited(n, false);

        for(int i=0; i<n; i++) {

            if(visited[i]) continue;

            int node = i;
            int length = 0;
            unordered_map<int, int> m;

            while(true) {

                // cycle detected
                if(visited[node]) {
                    if(m.find(node) != m.end()) {
                        maxLength = max(maxLength, length - m[node]);
                    }
                    break;
                }

                // normal traversal end
                if(edges[node] == -1) {
                    break;
                }

                visited[node] = true;
                m[node] = length;

                length++;
                node = edges[node];

            }

        }

        return maxLength;
    }
};
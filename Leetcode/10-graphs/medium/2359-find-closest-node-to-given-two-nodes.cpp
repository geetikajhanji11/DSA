/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        // traverse the entire path starting
        // from node1, and keep track of
        // distance of each node in the 
        // path from node1
        int n1 = node1;
        vector<bool> visited1(n, false);
        vector<int> distance1(n, INT_MAX);
        int i = 0;
        while(n1 != -1 && !visited1[n1]) {
            visited1[n1] = true;
            distance1[n1] = i;
            i++;
            n1 = edges[n1];
        }

        // traverse the entire path starting
        // from node2, and keep track of
        // distance of each node in the 
        // path from node2
        int n2 = node2;
        vector<bool> visited2(n, false);
        vector<int> distance2(n, INT_MAX);
        i = 0;
        while(n2 != -1 && !visited2[n2]) {
            visited2[n2] = true;
            distance2[n2] = i;
            i++;
            n2 = edges[n2];
        }

        // find the common nodes in
        // both paths from node1 and node2
        vector<int> common;
        for(int i=0; i<n; i++) {
            if(visited1[i] && visited2[i]) {
                common.push_back(i);
            }
        }

        // for every common node,
        // compare distances
        int minNode = INT_MAX;
        int minDist = INT_MAX; 
        for(int num : common) {
            int d1 = distance1[num];
            int d2 = distance2[num];
            int dist = max(d1, d2);
            if(dist < minDist) {
                minDist = dist;
                minNode = num;
            } else if(dist == minDist) {
                minNode = min(minNode, num);
            }
        }

        return minNode == INT_MAX ? -1 : minNode;
    }
};
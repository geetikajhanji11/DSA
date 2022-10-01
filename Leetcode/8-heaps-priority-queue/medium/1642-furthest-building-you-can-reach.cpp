/*******************************************************************
Ladder can reach upto any height
Minheap of size "ladders"
When minheap size == ladders + 1, 
    pop out minHeight from it and
    subtract this height from bricks

Time O(NlogK)
Space O(K)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {

        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(int i=0; i<heights.size() - 1; i++) {

            // do not need a ladder or brick 
            if(heights[i] >= heights[i+1]) continue;

            // push difference of height in minheap
            // i.e., possible bricks needed  
            int diff = heights[i+1] - heights[i]; 
            minHeap.push(diff);

            // if minheap has one extra element
            // i.e., minheap is completely full
            if(minHeap.size() == ladders + 1) {
                int minHeight = minHeap.top(); minHeap.pop();
                bricks -= minHeight; // have to use bricks instead
                if(bricks < 0) return i; 
            }   

        }

        return heights.size() - 1;
    }
};
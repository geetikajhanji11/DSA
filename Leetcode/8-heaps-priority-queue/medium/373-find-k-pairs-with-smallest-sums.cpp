/*******************************************************************
To avoid duplicates, i can also use additional boolean 2d vector
in which we can know if a position has already been visited

visited[i][j] = true/false 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// custom class
class Pair {
public:
    int i;
    int j;
    int sum;
    Pair(int i, int j, int sum) {
        this->i = i;
        this->j = j;
        this->sum = sum;
    }
};

// min heap for sum
class Compare {
public:
    bool operator()(Pair p1, Pair p2) {
        return p1.sum > p2.sum;
    }
};

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<Pair, vector<Pair>, Compare> minHeap;

        Pair newPair(0, 0, nums1[0] + nums2[0]);
        minHeap.push(newPair);

        vector<vector<int>> result;
        while(!minHeap.empty() && k > 0) {
            Pair poppedPair = minHeap.top(); minHeap.pop();

            result.push_back({nums1[poppedPair.i], nums2[poppedPair.j]});
            k--;

            // next ith element (j == 0) to avoid duplicates
            if(poppedPair.i + 1 < nums1.size() && poppedPair.j == 0) {
                int nextSum = nums1[poppedPair.i + 1] + nums2[poppedPair.j];
                Pair nextPair(poppedPair.i + 1, poppedPair.j, nextSum);
                minHeap.push(nextPair);
            }

            // next jth element
            if(poppedPair.j + 1 < nums2.size() && poppedPair.i < nums1.size()) {
                int nextSum = nums1[poppedPair.i] + nums2[poppedPair.j + 1];
                Pair nextPair(poppedPair.i, poppedPair.j + 1, nextSum);
                minHeap.push(nextPair);
            }

        }

        return result;
    }
};
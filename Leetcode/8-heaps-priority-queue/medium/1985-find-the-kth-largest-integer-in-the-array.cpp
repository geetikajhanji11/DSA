/*******************************************************************
["3","6","7","10"]
3
["3","6","7","10"]
4
["2","21","12","1"]
3
["2","21","12","1"]
1
["0","0"]
2
["0","1","1"]
2
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    class Compare {
    public:
        bool operator() (string &b, string &a) { 
            if (a.size() != b.size()) return a.size() < b.size();
            return  a < b;
        }
    };
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string, vector<string>, Compare> minHeap;
        for (string& num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};


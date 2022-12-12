/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Compare {
public:
    bool operator()(pair<char, int> p1, pair<char, int> p2) {
        return p1.second < p2.second;
    }
};

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> maxHeap;

        if(a > 0) maxHeap.push({'a', a});
        if(b > 0) maxHeap.push({'b', b});
        if(c > 0) maxHeap.push({'c', c});

        string result = "";

        while(!maxHeap.empty()) {

            auto currPair = maxHeap.top(); maxHeap.pop();
            char ch = currPair.first;
            int freq = currPair.second;

            int i = result.size() - 1;
            if(i >= 0 && i-1 >= 0 && result[i] == ch && result[i-1] == ch) {
                if(maxHeap.empty()) return result;

                auto nextPair = maxHeap.top(); maxHeap.pop();
                ch = nextPair.first;
                freq = nextPair.second;

                maxHeap.push(currPair);
            }

            result.push_back(ch);
            freq -= 1;

            if(freq > 0) {
                maxHeap.push({ch, freq});
            }
        }

        return result;
    }
};
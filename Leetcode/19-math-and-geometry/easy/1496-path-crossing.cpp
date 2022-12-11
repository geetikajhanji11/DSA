/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    bool isPathCrossing(string path) {
        
        unordered_map<char, pair<int, int>> direction;
        direction['N'] = {0, 1};
        direction['E'] = {1, 0};
        direction['S'] = {0, -1};
        direction['W'] = {-1, 0};
        
        int x = 0;
        int y = 0;

        set<pair<int, int>> s;
        
        for(char d : path) {
            
            s.insert({x, y});
            auto p = direction[d];
            
            x += p.first;
            y += p.second;

            if(s.find({x, y}) != s.end()) return true;
            
        }

        return false;
    }
};
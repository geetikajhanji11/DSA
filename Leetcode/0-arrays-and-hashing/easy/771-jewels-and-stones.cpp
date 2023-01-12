/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;

        for(char jewel : jewels) {
            s.insert(jewel);
        }

        int count = 0;
        for(char stone : stones) {
            if(s.find(stone) != s.end()) count++;
        }

        return count;
    }
};
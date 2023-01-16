/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int getUltimateParent(int node, vector<int> &parent) {
        if(parent[node] == node) return node;
        return parent[node] = getUltimateParent(parent[node], parent);
    }

    void unionAndFind(int ch1, int ch2, vector<int> &parent) {
        int up_ch1 = getUltimateParent(ch1, parent);
        int up_ch2 = getUltimateParent(ch2, parent);

        if(up_ch1 == up_ch2) return;

        parent[max(up_ch1, up_ch2)] = min(up_ch1, up_ch2);
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.length();

        vector<int> parent(26);
        for(int node=0; node<26; node++) {
            parent[node] = node;
        }

        for(int i=0; i<n; i++) {
            int ch1 = s1[i] - 'a';
            int ch2 = s2[i] - 'a';
            if(ch1 == ch2) continue;
            unionAndFind(ch1, ch2, parent);
        }

        string result;
        for(int i=0; i<baseStr.length(); i++) {
            int ch = baseStr[i] - 'a';
            char up = getUltimateParent(ch, parent) + 'a';
            result.push_back(up);
        }

        return result;
    }   
};
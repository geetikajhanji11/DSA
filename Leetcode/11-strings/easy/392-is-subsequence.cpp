/*******************************************************************
                    FOLLOW - UP
Follow-up: O(N) time for pre-processing, O(Mlog?) for each S.
Eg-1. s="abc", t="bahbgdca"
idx=[a={1,7}, b={0,3}, c={6}]
 i=0 ('a'): prev=1
 i=1 ('b'): prev=3
 i=2 ('c'): prev=6 (return true)
Eg-2. s="abc", t="bahgdcb"
idx=[a={1}, b={0,6}, c={5}]
 i=0 ('a'): prev=1
 i=1 ('b'): prev=6
 i=2 ('c'): prev=? (return false)

class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char, vector<int>> hash; //chars -> list of indices;
        for(int i=0; i<t.length();i++) hash[t[i]].push_back(i);
        
        int prev = -1;
        for(auto c : s){
            auto it = hash.find(c);
            if(it == hash.end()) return false;
            auto vec = it->second;
            int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); // find the first pos whose value is greater than prev
            if(pos == vec.size()) return false;
            prev = vec[pos];
        }
        return true;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string s, string t) {

    int i = 0;
    for(char ch : t) {
        if(s[i] == ch) {
            i++;
            if(i == s.length()) return true;
        }
    }        

    if(i == s.length()) return true;

    return false;
}

int main() {

    return 0;
}
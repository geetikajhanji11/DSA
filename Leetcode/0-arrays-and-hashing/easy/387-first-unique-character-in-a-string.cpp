/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int firstUniqChar(string s) {

    unordered_map<char, int> m;
    queue<int> q;        

    for(int i=0; i<s.length(); i++) {
        char ch = s[i];
        if(m.find(ch) == m.end()) {
            q.push(i);
        }
        m[ch]++;
    }

    while(!q.empty()) {
        int i = q.front();
        q.pop();
        if(m[s[i]] == 1) return i;
    }

    return -1;
}

int main() {

    return 0;
}
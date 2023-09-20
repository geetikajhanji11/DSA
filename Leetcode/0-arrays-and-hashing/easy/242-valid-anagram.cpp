/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAnagram(string s, string t) {
    if(s.length() != t.length()) return false;

    vector<int> count(27, 0);

    for(char ch : s) {
        int index = ch - 'a';
        count[index] += 1;
    }        

    for(char ch : t) {
        int index = ch - 'a';
        count[index] -= 1;
        if(count[index] < 0) return false;
    }

    return true;
}

// -------- ALTERNATE SOLUTION --------
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> m;

        for(char c : s) m[c]++;

        int totalZeros = 0;
        for(char c : t) {
            m[c]--;
            if(m[c] < 0) return false;
            if(m[c] == 0) totalZeros++;
        }

        return totalZeros == m.size();
    }
};

int main() {

    return 0;
}
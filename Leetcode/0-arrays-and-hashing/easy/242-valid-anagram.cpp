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

int main() {

    return 0;
}
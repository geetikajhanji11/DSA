/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int uniqueMorseRepresentations(vector<string>& words) {
    vector<string> morseCodes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};

    unordered_set<string> s;

    for(string word : words) {
        string morse = "";
        for(char ch : word) {
            morse += morseCodes[ch - 'a'];
        }
        s.insert(morse);
    }

    return s.size();
}

int main() {

    return 0;
}
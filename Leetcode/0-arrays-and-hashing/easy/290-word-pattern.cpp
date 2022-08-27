/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        
        unordered_map<char, string> charToString;
        unordered_map<string, char> stringToChar;

        // getting all words
        stringstream ss(s);
        string token;
        vector<string> words;
        while(getline(ss, token, ' ')) {
            words.push_back(token);
        }

        if(pattern.length() != words.size()) return false;

        for(int i=0; i<pattern.length(); i++) {

            char ch = pattern[i];
            string str = words[i];

            if(charToString.find(ch) == charToString.end()) {
                if(stringToChar.find(str) == stringToChar.end()) {
                    charToString[ch] = str;
                    stringToChar[str] = ch;
                } else return false;
            } else {
                if(stringToChar.find(str) == stringToChar.end()) return false;
                else {
                    bool valid = ch == stringToChar[str] && str == charToString[ch];
                    if(!valid) return false;
                }
            }
        }

        return true;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length() != t.length()) return false;
        
        unordered_map<char, char> s_to_t;
        unordered_map<char, char> t_to_s;

        for(int i=0; i<s.length(); i++) {

            // s does not exist
            if(s_to_t.find(s[i]) == s_to_t.end()) {
                if(t_to_s.find(t[i]) == t_to_s.end()) {
                    s_to_t[s[i]] = t[i];
                    t_to_s[t[i]] = s[i];
                } else return false;
            } 
            
            // s exists
            else {
                if(t_to_s.find(t[i]) != t_to_s.end()) {
                    if(s_to_t[s[i]] != t[i] || t_to_s[t[i]] != s[i]) {
                        return false;
                    }
                } else {
                    return false;
                }
            }   
        }

        return true;
    }
};
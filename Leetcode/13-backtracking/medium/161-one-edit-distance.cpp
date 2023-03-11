/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool isOneEditDistanceApart(bool used, int i, int j, string &s, string &t) {
        
        // base cases
        if(used && i == s.length() && j == t.length()) return true;
        
        if(i == s.length()) {
            if(used) return false;
            return (t.length() - j) == 1; 
        }

        if(j == t.length()) {
            if(used) return false;
            return (s.length() - i) == 1; 
        }

        // if same character
        if(s[i] == t[j]) return isOneEditDistanceApart(used, i+1, j+1, s, t);
        
        // recursive cases
        if(used) return false;

        bool canEdit = false;
        
        // insert one character in any position of S
        canEdit = canEdit || isOneEditDistanceApart(true, i, j+1, s, t);

        // delete one character in S
        canEdit = canEdit || isOneEditDistanceApart(true, i+1, j, s, t);

        // change any one character in S to other character
        canEdit = canEdit || isOneEditDistanceApart(true, i+1, j+1, s, t);

        return canEdit;
    }

public:
    bool isOneEditDistance(string &s, string &t) {
        if(s == t) return false;

        return isOneEditDistanceApart(false, 0, 0, s, t);
    }
};
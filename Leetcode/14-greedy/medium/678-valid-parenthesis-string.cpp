/*******************************************************************
Given s containing '(', ')', or '*', determine if valid
Ex. s = "()" -> true, s = "(*)" -> true, s = "(*))" -> true

Brute force: try both possibilities for each asterisk
Optimal: greedy, "balance", track min/max lefts

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ------------------- RECURSIVE -------------------
// ----- can do memoization with 2d matrix: [i][open]
// bool isValid(int i, int open, int close, string &s) {

//     if(i == s.length()) {
//         return open == close;
//     }

//     if(close > open) return false; // cannot recover from this

//     if(s[i] == '(') return isValid(i+1, open+1, close, s);
//     if(s[i] == ')') return isValid(i+1, open, close+1, s);
//     if(s[i] == '*') {
//         bool star_is_open = isValid(i+1, open+1, close, s);
//         bool star_is_close = isValid(i+1, open, close+1, s);
//         bool star_is_empty = isValid(i+1, open, close, s);
//         return star_is_open || star_is_close || star_is_empty;
//     }

//     return false;
// }

// bool checkValidString(string s) {
//     return isValid(0, 0, 0, s);
// }

// ------------------- GREEDY -------------------
bool checkValidString(string s) {
    int left_min = 0; // minimum number of ( a string can have to be valid
    int left_max = 0; // maximum number of ( a string can have to be valid

    for(char ch : s) {
        if(ch == '(') {
            left_min++;
            left_max++;
        }
        else if(ch == ')') {
            left_min--;
            left_max--;
        }
        else if(ch == '*') {
            left_min--;
            left_max++;
        }

        if(left_max < 0) return false;
        if(left_min < 0) {
            left_min = 0;
        }
    }

    if(left_min == 0) return true;
    else return false;
}

int main() {

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ---------- APPROACH - 1 ----------
// SPACE = O(1) 
string reverseWords(string s) {

    int n = s.length();
    string result = "";

    for(int i=0; i<n; i++) {
        if(s[i] == ' ') continue;;

        string word = "";
        while(i<n && isalnum(s[i])) {
            word += s[i];
            i++;
        }

        result = word + " " + result;
    }
    
    result.pop_back(); // removing last extra space
    return result;
}

// ---------- APPROACH - 1 ----------
// SPACE = O(N) 
string reverseWords(string s) {

    int n = s.length();
    stack<string> stck;

    for(int i=0; i<n; i++) {
        if(s[i] == ' ') continue;;

        string word = "";
        while(i<n && isalnum(s[i])) {
            word += s[i];
            i++;
        }
        stck.push(word);
    }

    string result = "";

    while(!stck.empty()) {
        result += stck.top() + " ";
        stck.pop();
    }

    result.pop_back();
    return result;
}

int main() {

    return 0;
}
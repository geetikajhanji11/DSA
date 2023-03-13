/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {

        vector<int> count(26, 0);
        vector<bool> inStack(26, false);
        
        // count frequency of each char
        for(char ch : s) count[ch - 'a']++;

        // maintain montonic increasing stack
        stack<char> stck;
        for(char ch : s) {
         
            if(count[ch-'a'] == 0) continue;
            
            if(inStack[ch-'a']) {
                count[ch-'a']--;
                continue;
            }

            while(!stck.empty() && (stck.top() > ch) && (count[stck.top()-'a'] > 0)) {
                inStack[stck.top()-'a'] = false;
                stck.pop();
            }

            count[ch-'a']--;
            stck.push(ch);
            inStack[ch-'a'] = true;

        }
        
        string result = "";
        while(!stck.empty()) {
            result = stck.top() + result;
            stck.pop();
        }

        return result;
    }
};
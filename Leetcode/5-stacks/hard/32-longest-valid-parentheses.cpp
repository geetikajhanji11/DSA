/*******************************************************************
Here, index -1 is set as the first parameter

The rule is simple:

(1) if strings are connected, 
    the parameter we set up must remain as the 
    starting point for measuring the distance

(2) if strings are disconnected, 
    the parameter we set up should be removed, 
    providing the distance between the starting point 
    and end point (length of the valid parenthesis)

The problem is that we don't have enough information about the 
disconnection point during the iteration.
So we need to set up a parameter in every place where connection is possible.

[1]. if open brackets > closed brackets currently 
        => set '(' as a new parameter
[2]. if closed brackets > open brackets currently 
        => set ')' as a new parameter
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {

        int longestLength = 0;

        // holds indexes of discontinuations
        stack<int> idxStack;
        idxStack.push(-1);

        for(int i=0; i<s.length(); i++) {

            if(s[i] == '(') {
                idxStack.push(i);
            } else {
                idxStack.pop();

                // the top value now in the stack
                // indicates the starting point of
                // discontinuation from where the 
                // valid substring starts
                if(idxStack.empty()) {
                    idxStack.push(i);
                } else {
                    longestLength = max(longestLength, i - idxStack.top());
                }
            }

        }

        return longestLength;
    }
};
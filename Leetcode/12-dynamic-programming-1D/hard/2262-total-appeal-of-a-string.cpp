/*******************************************************************
"abbca"

-------------------------------------------------
left (prefixes) | (char) | right (suffixes)
-------------------------------------------------

0)  a -> 5 (contributions in substrings = 1 * 5)
-------------------------------------------------
    left:
        -

    right:
    -
    b
    bb
    bbc
    bbca   

1)  b -> 8 (contributions in substrings = 2 * 4)
-------------------------------------------------
    left:
        -
        a

    right:
    -
    b
    bc
    bca   

2)  b -> 3 (contributions in substrings = 1 * 3)
-------------------------------------------------
    left:
        -
        b (X)
       ab (X)

    right:
    -
    c
    ca   

3)  c -> 3 (contributions in substrings = 4 * 2)
-------------------------------------------------
    left:
        -
        b 
       bb 
      abb 

    right:
    -
    a   

3)  a -> 4 (contributions in substrings = 4 * 1)
-------------------------------------------------
    left:
        -
        c
       bc 
      bbc 
     abbc (X)

    right:
    -  
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    long long appealSum(string s) {
        unordered_map<char, int> lastIndex;
        long long total = 0;

        for(int i=0; i<s.length(); i++) {

            long long left;
            long long right;

            // this character has been seen before
            // (it is a duplicate)
            if(lastIndex.find(s[i]) != lastIndex.end()) {
                left = i - lastIndex[s[i]];
                right = s.length() - i; 
            } else {
                left = i + 1;
                right = s.length() - i;
            }

            total += (left * right);
            lastIndex[s[i]] = i;

        }

        return total;
        
    }
};
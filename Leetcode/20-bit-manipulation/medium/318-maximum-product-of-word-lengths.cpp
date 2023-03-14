/*******************************************************************
a = 1 (1 left shift by 0)
b = 10 (1 left shift by 1)
c = 100 (1 left shift by 2)

000000|00010000000000000000000111 => abcw
000000|10000000000000000000000011 => baz
000000|00000000000100000000100000 => foo
000000|00000000100000000000000011 => bar
000000|00100010000010000000100000 => xtfn
000000|00000000000000000000111111 => abcdef
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        // find out bit value of each word
        vector<int> bitValue(n, 0);
        for(int i=0; i<n; i++) {
            for(char ch : words[i]) {
                int leftShiftFactor = ch - 'a';
                bitValue[i] = bitValue[i] | (1 << leftShiftFactor); 
            }
        }
        
        // two nested loops
        int result = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                
                // nothing is common between them
                if((bitValue[i] & bitValue[j]) == 0) {
                    int lengthProduct = words[i].length() * words[j].length();
                    if(lengthProduct > result) {
                        result = lengthProduct;
                    }
                }
            }
        }

        return result;
    }
};
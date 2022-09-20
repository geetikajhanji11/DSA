/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        int wordIdx = 1;

        for(int i=0; i<sentence.length(); i++) {
            
            int j = 0;
            for(; j<searchWord.length(); j++) {
                
                if(i == sentence.length()) break;
                if(sentence[i] == ' ') break;
                if(sentence[i] != searchWord[j]) break;

                i++;
            }
        
            if(j == searchWord.length()) return wordIdx;
            while(i < sentence.length() && sentence[i] != ' ') i++;

            wordIdx++;
        }

        return -1;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isAlienSorted(vector<string>& words, string order) {
    
    unordered_map<char, int> order_index;
    for(int i=0; i<order.length(); i++) {
        char ch = order[i];
        order_index[ch] = i;
    }

    // going over the words in pairs
    for(int i=0; i<words.size()-1; i++) {
        string word1 = words[i];
        string word2 = words[i+1];

        for(int idx=0; idx<word1.size(); idx++) {

            // length of word 2 is less than word 1, 
            // violates sorting logic
            if(idx == word2.length()) return false; 

            char ch1 = word1[idx];
            char ch2 = word2[idx];
            if(ch1 != ch2) {
                if(order_index[ch1] < order_index[ch2]) break; // sorted
                return false; // not sorted
            }
        }
    }
    return true;
}

int main() {

    return 0;
}
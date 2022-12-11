/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> findWords(vector<string>& words) {

        vector<string> arrangement = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<int> getRow(26, 0);
        for(int i=0; i<arrangement.size(); i++) {
            for(char ch : arrangement[i]) {
                getRow[ch - 'a'] = i; 
            } 
        }

        vector<string> result;
        for(string word : words) {
            int row = getRow[tolower(word[0])-'a'];
            bool isValid = true;
            for(int i=1; i<word.length(); i++) {
                if(getRow[tolower(word[i])-'a'] != row) {
                    isValid = false;
                    break;
                }
            }
            if(isValid) {
                result.push_back(word);
            }
        }

        return result;
    }
};
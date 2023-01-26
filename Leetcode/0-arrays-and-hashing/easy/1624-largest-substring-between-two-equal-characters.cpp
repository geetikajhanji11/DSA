/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {

        vector<int> position(26, -1);

        int maxLength = -1;
        for(int i=0; i<s.length(); i++) {
            int letter = s[i] - 'a';

            if(position[letter] == -1) {
                position[letter] = i;
                continue;
            }

            maxLength = max(maxLength, i - position[letter] - 1);
        }

        return maxLength;
    }
};
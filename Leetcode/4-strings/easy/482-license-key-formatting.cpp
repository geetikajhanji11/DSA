/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string result = "";

        int groupLength = 0;
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i] == '-') continue;
            
            if(groupLength == k) {
                result.push_back('-');
                groupLength = 0;
            }

            result.push_back(toupper(s[i]));
            groupLength++;
        }

        reverse(result.begin(), result.end());
        return result;
    }
};
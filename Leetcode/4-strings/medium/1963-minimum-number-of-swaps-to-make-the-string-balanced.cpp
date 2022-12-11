/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(string s) {
        
        int maxClose = 0;
        int close = 0;

        for(char ch : s) {
            if(ch ==']') close++;
            else close--;
            maxClose = max(maxClose, close);
        }

        return (maxClose + 1) / 2;
    }
};
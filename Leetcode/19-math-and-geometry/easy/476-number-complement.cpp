/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        string s = bitset<32> (num).to_string();

        int i = 0;
        while(i < s.length() && s[i] == '0') i++;

        int p = 0;
        int complement = 0;
        for(int j=s.length()-1; j>=i; j--) {
            if(s[j] == '0') {
                complement += pow(2, p);
            }
            p++;
        }
        return complement;
    }
};
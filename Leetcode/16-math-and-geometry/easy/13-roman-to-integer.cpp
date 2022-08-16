/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> RtoI;
    RtoI['I'] = 1;
    RtoI['V'] = 5;
    RtoI['X'] = 10;
    RtoI['L'] = 50;
    RtoI['C'] = 100;
    RtoI['D'] = 500;
    RtoI['M'] = 1000;

    int result = 0;

    for(int i=0; i<s.length(); i++) {

        char currRoman = s[i];
        char nextRoman = ' ';
        if(i+1 < s.length()) nextRoman = s[i+1];

        int currResult = 0;

        if((currRoman == 'I' && (nextRoman == 'V' || nextRoman == 'X')) ||
            (currRoman == 'X' && (nextRoman == 'L' || nextRoman == 'C')) ||
            (currRoman == 'C' && (nextRoman == 'D' || nextRoman == 'M'))
        ) {
            result += (RtoI[nextRoman] - RtoI[currRoman]);
            i++;
            continue;
        } 
        
        result += RtoI[currRoman];
    }    

    return result;    
}

int main() {

    return 0;
}
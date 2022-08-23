/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string convert(string s, int numRows) {

    if(numRows == 1) return s;
    int colGaps = numRows - 2;
    string result = "";
    
    for(int row=0; row<numRows; row++) {

        if(row == 0 || row == numRows-1) {
            int i = row;
            if(i >= s.length()) break;
            result += s[i];
            while(i + numRows + colGaps < s.length()) {
                result += s[i + numRows + colGaps];
                i = i + numRows + colGaps;
            }
            continue;
        }

        int factor = row * 2;

        // alternate b/w these 2
        int idx1 = (numRows + colGaps) - factor;
        int idx2 = factor;

        int i = row;
        if(i >= s.length()) break;

        result += s[i];
        while(i + idx1 < s.length()) {
            result += s[i + idx1];
            if(i + idx1 + idx2 < s.length()) {
                result += s[i + idx1 + idx2];
            }
            i = i + idx1 + idx2;
        }

    }

    return result;
}

int main() {

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int titleToNumber(string columnTitle) {
    int n = columnTitle.length() - 1;

    int columnNumber = 0;
    for(char letter : columnTitle) {
        int x = (letter - 'A') + 1;
        columnNumber += (x * pow(26, n));
        n--;
    }
    
    return columnNumber;
}

int main() {

    return 0;
}
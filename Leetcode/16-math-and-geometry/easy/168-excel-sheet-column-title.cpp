/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string convertToTitle(int columnNumber) {

    string result = "";

    while(columnNumber != 0) {
        columnNumber -= 1;

        int rem = columnNumber % 26;
        char ch = ('A' + rem);

        result += ch;
        columnNumber /= 26; 
    }

    reverse(result.begin(), result.end());
    return result;

}

int main() {

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {

    string str = "1";
    n = n - 1;

    while(n != 0) {
        string temp = "";
        for(int i=0; i<str.length(); i++) {
            char ch = str[i];
            int count = 1;
            while(i+1 < str.length() && str[i+1] == ch) {
                count++;
                i++;
            }
            temp += to_string(count);
            temp += ch;
        }
        str = temp;
        n--;
    }

    return str;
}

int main() {

    return 0;
}
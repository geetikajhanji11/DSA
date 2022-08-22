/*******************************************************************
"42"
"   -42"
"4193 with words"
"4193 with words 92383"
"word lol    383"
"2147483647654"
"2147483647"
"word lol    383-"
"   -9"
"mfvk  98"
"-946    78"
"-91283472332"
"+1"
"+   1"
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int myAtoi(string s) {

    bool isNegative = false;
    bool foundNumber = false;
    int number = 0;

    for(int i=0; i<s.length(); i++) {

        char ch = s[i];

        if(!foundNumber && ch == ' ') continue;
        if(!foundNumber && (ch == '-' || ch == '+') && i+1 < s.length() && isdigit(s[i+1])) continue;
        if(!isdigit(ch)) break;

        if(!foundNumber && isdigit(ch)) {
            if(i-1 >= 0 && s[i-1] == '-') isNegative = true;
            foundNumber = true;
        }

        if(foundNumber) {
            int digit = ch - '0';
            
            if(!isNegative && number > INT_MAX / 10) return INT_MAX;
            if(!isNegative && number == INT_MAX / 10 && digit >= INT_MAX % 10) return INT_MAX;
            
            if(isNegative && (((-1) * number) < INT_MIN / 10)) return INT_MIN;
            if(isNegative && (((-1) * number) == INT_MIN / 10) && digit >= 8) return INT_MIN;
            number = number * 10 + digit; 
        }

    }

    if(isNegative) return (-1) * number;
    return number;
}

int main() {

}
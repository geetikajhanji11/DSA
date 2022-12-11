/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int reverse(int x) {

    int result = 0;

    while(x != 0) {
        int digit = x % 10;
        x = x / 10;

        if(result > INT_MAX / 10 || (result == INT_MAX / 10 && digit >= INT_MAX % 10)) return 0;
        if(result < INT_MIN / 10 || (result == INT_MIN / 10 && digit <= INT_MIN % 10)) return 0;

        result = (result * 10) + digit;
    }

    return result;
}

int main() {

    return 0;
}
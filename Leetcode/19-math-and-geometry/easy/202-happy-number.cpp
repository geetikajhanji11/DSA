/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isHappy(int n) {

    unordered_set<int> s;
    while(n != 1) {
        s.insert(n);
        int sum = 0;
        while(n != 0) {
            int rem = n % 10;
            sum += (rem * rem);
            n = n / 10;
        }
        n = sum;
        if(s.find(n) != s.end()) return false;
    }

    return true;
}

int main() {

    return 0;
}
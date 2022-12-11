/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;

    vector<int> num;

    while(x != 0) {
        num.push_back(x % 10);
        x = x / 10;
    }    

    int i = 0;
    int j = num.size() - 1;

    while(i < j) {
        if(num[i] != num[j]) return false;
        i++;
        j--;
    }

    return true;
}

int main() {

    return 0;
}
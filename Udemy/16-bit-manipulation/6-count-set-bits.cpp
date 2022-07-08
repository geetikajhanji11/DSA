/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// METHOD-1
int count_1s(int num) {
    int ctr = 0;
    while(num != 0) {
        ctr++;
        num = num & (num - 1); // removes last set bit
    }
    return ctr;
}

// METHOD-2
int cnt_1s(int num) {
    int ctr = 0;
    while(num != 0) {
        int last_bit = num & 1 == 0 ? 0 : 1;
        if(last_bit == 1) ctr++;
        num = num>>1;
    }
    return ctr;
}

int main() {

    cout<<count_1s(15)<<endl;
    cout<<cnt_1s(15)<<endl;
    return 0;
}
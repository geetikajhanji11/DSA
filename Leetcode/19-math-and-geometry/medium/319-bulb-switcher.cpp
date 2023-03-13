/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bulbSwitch(int n) {
        int num = 1;

        // count number of perfect squares in [0,n]
        int ctr = 0;
        while((long long)num * num <= n) {
            num++;
            ctr++;
        }

        return ctr;
    }
};
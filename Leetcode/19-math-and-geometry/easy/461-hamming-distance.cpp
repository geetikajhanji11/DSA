/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;

        int ones = 0;
        while(n != 0) {
            n = n & (n - 1);
            ones++;
        }

        return ones;
    }
};
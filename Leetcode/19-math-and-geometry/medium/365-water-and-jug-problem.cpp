/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int hcf(int n1, int n2) {
        if (n2 != 0) return hcf(n2, n1 % n2);
        else return n1;
    }

public:

    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        int upperLimit = jug1Capacity + jug2Capacity;
        if(targetCapacity > upperLimit) return false;

        int gcd = hcf(jug1Capacity, jug2Capacity);

        return targetCapacity % gcd == 0;        

    }
};
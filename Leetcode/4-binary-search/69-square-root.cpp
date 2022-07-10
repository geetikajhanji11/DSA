/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {

    int integerPart = 0;
    int low = 0;
    int high = x;

    // binary search for integer part
    while(low <= high) {
        int mid = (low + high) / 2;
        int square = mid * mid;
        
        // perfect square
        if(square == x) return mid;

        // find highest value of "square" closer to n
        if(square < x) {
            integerPart = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return integerPart;
}

int main() {

    return 0;
}
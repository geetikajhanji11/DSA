/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        int low = 0;
        int high = num;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            if((long long)mid * mid > INT_MAX) {
                high = mid - 1;
                continue;
            }
            
            int square = mid * mid;

            if(square == num) return true;
            else if(square < num) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string toHex(int num) {
        if(num == 0) return "0";

        int base = 16;
        unsigned int n = num;
        string result = "";
        
        while(n > 0) {
            int rem = n % base;
            
            if(rem < 10) {
                result += to_string(rem);
            } else {
                result += ('a' + (rem % 10));
            }

            n = n / base;
        }
        
        reverse(result.begin(), result.end());

        return result;
    }
};
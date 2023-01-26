/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(numerator == 0) return "0";
        
        bool isNegative = (numerator < 0) ^ (denominator < 0);
        numerator = abs(numerator);
        denominator = abs(denominator);

        long long q = numerator / denominator;
        long long rem = numerator % denominator;

        string result;

        // append integral part
        result += to_string(q);

        // map for holding visited values 
        // and index at which they were vistied
        unordered_map<long long, long long> remToIndex;

        // include the initial numerator in map
        if(rem != numerator) {
            remToIndex[numerator] = 0;
        } 
        if(rem != 0) result += ".";

        // for checking if fraction is recurring
        int index = -1; 
        
        // simulate the division process
        while(rem != 0) {

            if(remToIndex.find(rem) != remToIndex.end()) {
                index = remToIndex[rem];
                break;
            }
            remToIndex[rem] = result.size() - 1;

            rem *= 10;

            if(denominator > rem) {
                result += "0";
                continue;
            }

            long long newQ = rem / denominator;
            long long newRem = rem % denominator;

            result += to_string(newQ);
            rem = newRem;
        }

        // for including - or ( and )
        string modifiedResult = "";
        if(isNegative) modifiedResult += "-";

        // recurring 
        if(index != -1) {
            for(int i=0; i<result.size(); i++) {
                modifiedResult += result[i];
                if(i == index) {
                    modifiedResult += "(";
                }
            }
            modifiedResult += ")";
        } 
        
        // non recurring
        else {
            modifiedResult += result;
        }

        // result
        return modifiedResult;

    }
};


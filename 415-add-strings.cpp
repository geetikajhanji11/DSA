/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length() - 1;
        int j = num2.length() - 1;

        string result = "";

        int carry = 0;
        while(i >= 0 && j >= 0) {
            int n1 = num1[i] - '0';
            int n2 = num2[j] - '0';

            int sum = n1 + n2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            result = to_string(sum) + result;

            i--;
            j--;
            
        }

        while(i >= 0) {
            int n1 = num1[i] - '0';
            int sum = n1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            result = to_string(sum) + result;
            i--;
        }

        while(j >= 0) {
            int n2 = num2[j] - '0';
            int sum = n2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            result = to_string(sum) + result;
            j--;
        }

        if(carry > 0) {
            result = to_string(carry) + result;
        }


        return result;
    }
};
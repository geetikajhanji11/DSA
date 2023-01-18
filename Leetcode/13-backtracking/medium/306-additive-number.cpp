/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    // ----------------- add two strings -----------------
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

    // ----------------- check for leading zero -----------------
    bool isLeadingZero(string &num) {
        return num.length() > 1 && num[0] == '0';
    }

    // ----------------- backtracking -----------------
    bool isAdditive(int idx, string num1, string num2, string &num) {
        if(idx == num.length()) return true;

        string sum = addStrings(num1, num2);        
        string currNum = "";

        for(int i=idx; i<num.length(); i++) {
            currNum.push_back(num[i]);
            if(isLeadingZero(currNum)) return false;
            if(currNum.length() > sum.length()) return false;

            if(currNum == sum) {
                if(isAdditive(i+1, num2, currNum, num)) return true;
            }
        }

        return false;
    }

public:
    // ----------------- driver -----------------
    bool isAdditiveNumber(string num) {

        // should be at least 3 digits
        if(num.length() < 3) return false;

        // make every combination of "num1" and "num2"
        string num1 = "";
        for(int i=0; i<num.length() - 2; i++) {
            num1.push_back(num[i]);
            if(isLeadingZero(num1)) break;
            
            string num2 = "";
            for(int j=i+1; j<num.length() - 1; j++) {
                num2.push_back(num[j]);
                if(isLeadingZero(num2)) break;

                // recursive call
                if(isAdditive(j+1, num1, num2, num)) return true;
            }
        }

        return false;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    string INT_MAX_STRING = "2147483647";
    vector<int> validSeq;

    // checks if the string is valid:
    // no leading zeroes
    // 0 <= num < INT_MAX
    bool isValid(string &num) {
        if(num.length() > 1 && num[0] == '0') return false;
        if(num.length() > INT_MAX_STRING.length()) return false;
        if(num.length() == INT_MAX_STRING.length() && num > INT_MAX_STRING) return false;
        return true;  
    }

    // add two strings and return final result
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

    // main recursive function
    void dfs(int i, string num2String, string sumString, vector<int> seq, string &num) {
        
        // found the sequence
        if(i >= num.length()) {
            validSeq = seq;
            return;
        }

        // invalid sum to find 
        if(!isValid(sumString)) return;

        // find sum in current length
        string currString = "";
        for(int j=i; j<num.length(); j++) {
            currString += num[j];

            if(currString.length() < sumString.length()) continue;
            if(currString.length() > sumString.length()) break;

            // found next sequence
            if(currString == sumString) {
                seq.push_back(stoi(sumString));

                string newSumString = addStrings(num2String, sumString);

                dfs(j+1, sumString, newSumString, seq, num);
            }

        }
    }

public:
    vector<int> splitIntoFibonacci(string num) {
        
        // -------- outer loop => num1 --------
        string num1String = "";
        for(int i=0; i<num.length()-2; i++) {

            // already found a sequence
            if(validSeq.size() >= 3) break;

            // add to num1 and check validity
            num1String.push_back(num[i]);
            if(!isValid(num1String)) break;

            // -------- inner loop => num2 --------
            string num2String = "";
            for(int j=i+1; j<num.length()-1; j++) {

                // already found a sequence
                if(validSeq.size() >= 3) break;
        
                // add to num2 and check validity
                num2String.push_back(num[j]);
                if(!isValid(num2String)) break;
        
                // add the two VALID NUMS
                string sumString = addStrings(num1String, num2String);
                dfs(j+1, num2String, sumString, {stoi(num1String), stoi(num2String)}, num);
            }
        }

        return validSeq;

    }
};
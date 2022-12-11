/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    vector<string> RANK = {"", "Thousand", "Million", "Billion"};
    vector<string> LESS_THAN_TWENTY = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> TENS = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

public:

    // convert number to string
    string numberToWords(int num) {
        
        // base case
        if(num == 0) return "Zero";
        
        // result string
        string result = "";

        // iterate until whole number is traversed
        int r = 0; // current rank of group
        while(num != 0) {

            // preparing for group's processing
            int digitCount = 0;
            int curr = 0;
            string groupWord = "";

            // group of three digits
            while(num != 0 && digitCount < 3) {
                
                int digit = num % 10;
                curr = (digit * pow(10, digitCount)) + curr;

                // single digit
                if(digitCount == 0) {
                    groupWord = LESS_THAN_TWENTY[curr];
                } 
                
                // two digits
                else if(digitCount == 1) {
                    if(curr < 20) {
                        groupWord = LESS_THAN_TWENTY[curr];
                    } else {
                        groupWord = TENS[digit] + groupWord;
                    }
                }

                // three digits
                else if(digitCount == 2) {
                    string x = (digit == 0) ? "" : LESS_THAN_TWENTY[digit] + "Hundred";
                    groupWord = x + groupWord;
                }

                // changes made for next group
                num = num / 10;
                digitCount++;
            }

            // designate the rank for current group
            if(digitCount <= 3) {
                groupWord = groupWord + RANK[r];
            }

            // if the current number is 0,
            // do not include it in final result
            if(curr != 0) {
                result = groupWord + result;
            }
            
            // increase rank for next iteration
            r++;
        }

        // add spaces before every capital character
        string res = "";
        res += result[0];
        for(int i=1; i<result.length(); i++) {
            char ch = result[i];
            if(isupper(ch)) {
                res += ' ';
            }
            res += ch;
        }

        return res;

    }
};
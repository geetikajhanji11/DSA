/*******************************************************************

Given 2 ints represented as strings, return product, also represented as a string
Ex. num1 = "2" num2 = "3" -> "6", num1 = "123" num2 = "456" -> "56088"

Standard multiplication, right to left per digit, compute sums & carries at each pos

Time: O(m x n)
Space: O(m + n)


class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size();
        int n = num2.size();
        
        string result(m + n, '0');
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (result[i + j + 1] - '0');
                result[i + j + 1] = sum % 10 + '0';
                result[i + j] += sum / 10;
            }
        }
        
        for (int i = 0; i < m + n; i++) {
            if (result[i] != '0') {
                return result.substr(i);
            }
        }
        return "0";
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int toDigit(char ch) {
    int digit = ch - '0';
    return digit;
}

string multiply(string num1, string num2) {

    // how many zeroes have to be appended at the end
    int zeroes = 0; 

    vector<string> intermediates;
    int len = num1.length() + num2.length(); // handle -ve value

    for(int i=num1.length()-1; i>=0; i--) {

        int multiplier = toDigit(num1[i]);
        int carry = 0;
        string curr(len, '0');
        int k = len - 1 - zeroes;

        for(int j=num2.length()-1; j>=0; j--) {
            int digit =  toDigit(num2[j]);
            int result = (multiplier * digit) + carry;

            // cout<<"\ndigit = "<<digit<<", res = "<<result;

            carry = result / 10;
            int rem = result % 10;
            
            // cout<<"\nrem = "<<rem;
            curr[k] = to_string(rem)[0];
            k--;
        }

        if(carry != 0) {
            curr[k] = to_string(carry)[0];
        }

        intermediates.push_back(curr);
        zeroes++;
    }        

    for(string s : intermediates) {
        cout<<s<<endl;
    }

    string result(len, '0');
    
    int carry = 0;
    for(int i=len-1; i>=0; i--) {
        int sum = carry;
        for(string intermediate : intermediates) {
            int digit = toDigit(intermediate[i]); 
            sum += digit;
        }
        carry = sum / 10;
        sum = sum % 10;
        result[i] = to_string(sum)[0];
    }

    // remove starting zeroes
    int i = 0;
    while(result[i] == '0') i++;
    int finalLen = len - i;

    cout<<"\n i = "<<i;
    cout<<"\n finalLen = "<<finalLen;

    if(finalLen == 0) return "0";
    return result.substr(i, finalLen);
}

int main() {


    string ans = multiply("123", "4");
    cout<<"\n\nans = "<<ans;
    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        
        int carry = 0;
        int i = num.size() - 1;

        vector<int> helper;

        while(k != 0) {
            int rem = k % 10;

            if(i >= 0) {
                num[i] += rem + carry;
                carry = num[i] / 10;
                num[i] = num[i] % 10;
                i--;
            } else {
                int sum = rem + carry;
                carry = sum / 10;
                sum = sum % 10;
                helper.push_back(sum);
            }

            k = k / 10;
        }

        while(i >= 0) {
            num[i] += carry;
            carry = num[i] / 10;
            num[i] = num[i] % 10;
            i--;
        }
     
        if(carry != 0) helper.push_back(carry);
        reverse(helper.begin(), helper.end());
       

        helper.insert(helper.end(), num.begin(), num.end());

        return helper;
    }
};
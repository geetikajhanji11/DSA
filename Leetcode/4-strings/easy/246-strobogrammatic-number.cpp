/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// OJ: https://leetcode.com/problems/strobogrammatic-number/
// Time: O(N)
// Space: O(1)
class Solution {

    bool same(char a, char b) {
        return a == b && (a == '0' || a == '1' || a == '8');
    }

    bool match(char a, char b) {
        return same(a, b) || 
                (a == '6' && b == '9') || 
                (a == '9' && b == '6');
    }

public:
    bool isStrobogrammatic(string num) {
        int i = 0;
        int j = num.size() - 1;

        while(i <= j) {
            if (!match(num[i], num[j])) return false;
            i++;
            j--;
        }

        return true;
    }
};

// **************** MY SOLUTION ****************
class Solution {
    vector<char> stromNum = {'0', '1', 'x', 'x', 'x', 'x', '9', 'x', '8', '6'};
public:
    bool isStrobogrammatic(string &num) {
        string revNum = num;
        reverse(revNum.begin(), revNum.end());

        for(int i=0; i<revNum.length(); i++) {
            int digit = revNum[i] - '0';
            if(stromNum[digit] == 'x') return false;
            revNum[i] = stromNum[digit];
        }

        return revNum == num;
    }
};
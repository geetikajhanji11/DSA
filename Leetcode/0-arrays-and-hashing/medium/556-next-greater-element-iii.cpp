/*******************************************************************
Input:
12345 => 12354
17373 => 17733
1382987 => 1387289
1382978 => 1382987
54321 => -1

SIMILAR TO NEXT PERMUTATION
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        string digits = to_string(n);
        next_permutation(begin(digits), end(digits));
        auto res = stoll(digits);
        return (res > INT_MAX || res <= n) ? -1 : res;
    }
};

// class Solution {

//     void reverseRange(int i, int j, string &s) {
//         while(i < j) {
//             swap(s[i], s[j]);
//             i++;
//             j--;
//         }
//     }

// public:
//     int nextGreaterElement(int n) {
//         string s = to_string(n);

//         int length = s.length();

//         // decreasing order from back
//         //      i
//         // 1382[9]87
//         int i = length - 1;
//         while(i-1 >= 0 && s[i-1] > s[i]) i--;

//         if(i-1 >= 0) {
//             reverseRange(i-1, length-1, s);
//         }
//         else if(i == 0) return -1;
//         else if(i == length - 1) {
//             swap(s[i-1], s[i]);
//         }

//         return stoi(s);
//     }
// };
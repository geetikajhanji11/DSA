/**************************************************************

https://www.youtube.com/watch?v=0snEunUacZY&ab_channel=NeetCode

Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all
possible letter combinations that the number could represent.
Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) 
is given below. Note that 1 does not map to any letters.

2: abc
3: def
4: ghi
5: jkl
6: mno
7: pqrs
8: tuv
9: wxyv 

Example 1:
    Input: digits = "23"
    Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
    
Example 2:
    Input: digits = ""
    Output: []

Example 3:
    Input: digits = "2"
    Output: ["a","b","c"]

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;


void recur(vector<string> &result, string curr, string digits, unordered_map<char, string> &mp, int i) {

    if(i == digits.length()) {
        result.push_back(curr);
        return;
    }

    char digit = digits[i];
    string letters = mp[digit];
    for(char letter : letters) {
        recur(result, curr + letter, digits, mp, i + 1);
    }
    
}

vector<string> letterCombinations(string digits) {
    
    vector<string> result;
    unordered_map<char, string> mp;
    mp['2'] = "abc";
    mp['3'] = "def";
    mp['4'] = "ghi";
    mp['5'] = "jkl";
    mp['6'] = "mno";
    mp['7'] = "pqrs";
    mp['8'] = "tuv";
    mp['9'] = "wxyz";

    recur(result, "", digits, mp, 0);
    
    return result;
}


// main function 
int main() {
    
    vector<string> result = letterCombinations("23");
    for(string str : result) {
        cout<<str<<endl;
    }
    
}
/*******************************************************************
Given cell phone pad, return all possible letter combos that the 
number could represent
Ex. digits = "23" -> ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Hash map all digits to letters, add 1 letter at a time for each digit, 
then backtrack undo

Time: O(n x 4^n)
Space: O(n x 4^n)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int i, string curr, string &digits, unordered_map<char, string> &m, vector<string> &result) {
    if(i == digits.length()) {
        result.push_back(curr);
        return;
    }

    for(char letter : m[digits[i]]) {
        dfs(i+1, curr+letter, digits, m, result);
    }
}

vector<string> letterCombinations(string digits) {
    if(digits == "") return {};
    
    unordered_map<char, string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";        
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";
    vector<string> result;

    dfs(0, "", digits, m, result);

    return result;
}

int main() {

    return 0;
}
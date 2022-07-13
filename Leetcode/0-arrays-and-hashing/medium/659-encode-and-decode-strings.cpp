/*******************************************************************
Availabale on LintCode
https://www.lintcode.com/problem/659/

Design algorithm to encode/decode: list of strings <-> string

Encode/decode w/ non-ASCII delimiter: {len of str, "#", str}

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        string encoded_string = "";
        for(string str : strs) {
            int length = str.length();
            encoded_string += to_string(length) + '#' + str;
        }
        return encoded_string;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        vector<string> result;

        int i = 0;
        while(i < str.length()) {
            int curr_length = 0;
            string curr_str = "";
            while(str[i] != '#') {
                int num = str[i] - '0';
                curr_length = curr_length * 10 + num;
                i++;
            }
            i++; // to skip #

            while(curr_length != 0) {
                curr_str += str[i];
                curr_length--;
                i++;
            }
            result.push_back(curr_str);
        }

        return result;
    }
};

int main() {

    vector<string> strs = {"Hello", "how", "#kdfn", "84nef", "=20"};

    Solution sol;
    string s = sol.encode(strs);
    auto ans = sol.decode(s);

    for(auto x : ans) cout<<x<<endl;
    return 0;
}
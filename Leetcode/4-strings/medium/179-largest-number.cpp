/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool compare(string a, string b) {
        if(a[0] == b[0]) {
            return a + b > b + a;
        }
        return a[0] > b[0];
    }
public:
    string largestNumber(vector<int>& nums) {

        vector<string> numsStr;
        for(int num : nums) {
            numsStr.push_back(to_string(num));
        }
        
        sort(numsStr.begin(), numsStr.end(), compare);

        string result = "";
        for(string s : numsStr) {
            result += s;
        }

        // remove leading zero (handle test cases as [0,0,0,0])
        int i=0;
        while(i < result.length() && result[i] == '0') i++;
        result = result.substr(i, result.length() - i);
        if(result.length() == 0) return "0";

        return result;
    }
};
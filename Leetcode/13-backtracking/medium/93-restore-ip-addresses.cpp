/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool is_valid(string s) {
    if(s.length() == 0) return false;
    if(s.length() >= 2 && s[0] == '0') return false;
    int num = stoi(s);
    return num <= 255;
}

void dfs(int i, string curr, int dots, int max_digits, string s, vector<string> &result) {
    
    if(i > s.length()) return;
    if(dots == 0 && i != s.length()) return;

    if(i == s.length()) {
        if(dots == 0) result.push_back(curr);
        else return;
    }

    for(int len=1; len<=max_digits; len++) {
        string number = s.substr(i, len);
        if(is_valid(number)) {
            string partition = number + ".";
            dfs(i+len, curr+partition, dots-1, max_digits, s, result);
        }
    }

}

vector<string> restoreIpAddresses(string s) {
    int length = s.length();

    int max_digits = 0;
    if(length > 12) return {};
    else if(8 < length <= 12) max_digits = 3;
    else if(4 < length <= 8) max_digits = 2;
    else if(length == 4) max_digits = 1;
    else return {};

    vector<string> result;

    dfs(0, "", 4, max_digits, s, result);

    for(int i=0; i<result.size(); i++) {
        result[i].pop_back();
    }

    return result;

}

int main() {

    auto ans = restoreIpAddresses("25525511135");

    cout<<"\nans\n";
    for(string s : ans) cout<<s<<endl;

    return 0;
}
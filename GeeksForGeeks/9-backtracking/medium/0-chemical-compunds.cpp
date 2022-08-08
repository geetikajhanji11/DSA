/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void dfs(int i, string curr, string &s, unordered_set<string> &hash_set, vector<string> &result) {
    if(i == s.length()) {
        result.push_back(curr);
        return;
    }

    string s1 = s.substr(i, 1);
    string s2 = i+1 < s.length() ? s.substr(i, 2) : "";

    if(hash_set.find(s1) != hash_set.end()) {
        s1[0] = toupper(s1[0]);
        dfs(i+1, curr + s1, s, hash_set, result);
    }

    if(s2.length() != 0 && hash_set.find(s2) != hash_set.end()) {
        s2[0] = toupper(s2[0]);
        dfs(i+2, curr + s2, s, hash_set, result);
    }
}

vector<string> chemicalCombinations(string s) {
    unordered_set<string> hash_set;
    vector<string> result;

    // articli
    hash_set.insert("ar");
    hash_set.insert("ti");
    hash_set.insert("i");
    hash_set.insert("cl");
    hash_set.insert("c");
    hash_set.insert("li");

    dfs(0, "", s, hash_set, result);

    return result;
}

int main() {


    auto res = chemicalCombinations("articli");
    for(string s : res) cout<<s<<endl;
    return 0;
}
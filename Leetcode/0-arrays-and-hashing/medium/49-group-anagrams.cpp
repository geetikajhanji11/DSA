/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

string getKey(string str) {
    vector<int> count(26, 0);
    for(char ch : str) {
        int index = ch - 'a';
        count[index] += 1;
    }
    
    string key = "";
    for(int num : count) {
        key += to_string(num) + ',';
    }
    return key;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> m;

    for(string str : strs) {
        string key = getKey(str);
        m[key].push_back(str);
    }

    vector<vector<string>> result;
    for(auto it=m.begin(); it != m.end(); it++) {
        result.push_back(it->second);
    }

    return result;
}

int main() {

    vector<string> arr = {"bdddddddddd","bbbbbbbbbbc"};

    auto res = groupAnagrams(arr);
    for(auto v : res) {
        for(auto a : v) cout<<a<<", ";
        cout<<endl;
    }
    return 0;
}
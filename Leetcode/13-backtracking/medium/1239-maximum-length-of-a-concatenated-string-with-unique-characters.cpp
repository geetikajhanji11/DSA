/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

bool can_be_concatenated(string &s1, string &s2) {
    unordered_set<char> s;
    for(char ch : s1) s.insert(ch);

    for(char ch : s2) {
        if(s.find(ch) != s.end()) return false;
    }

    return true;
}

void dfs(int i, string curr, vector<string>& arr, int &length) {
    if(i == arr.size()) return;

    string str = "";
    for(int j=i; j<arr.size(); j++) {
        if(can_be_concatenated(curr, arr[j])) {
            // string new_string = curr + arr[j];
            // cout<<new_string<<endl;
            int new_length = curr.length() + arr[j].length();
            length = max(length, new_length);
            dfs(j+1, curr + arr[j], arr, length);
        }
    }
}

bool is_valid(string str) {

    unordered_set<char> s;
    for(char ch : str) {
        if(s.find(ch) != s.end()) return false;
        s.insert(ch);
    }

    return true;
}

int maxLength(vector<string>& arr) {

    vector<string> new_arr;
    for(string str : arr) {
        if(is_valid(str)) {
            new_arr.push_back(str);
        }
    }

    int length = 0;
    dfs(0, "", new_arr, length);

    return length;
}

int main() {

    vector<string> arr = {"un","iq","ue"};
    cout<<maxLength(arr);
    return 0;
}
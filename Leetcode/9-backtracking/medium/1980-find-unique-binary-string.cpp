/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string generate_num(string curr, unordered_set<string> &s, int n) {

    if(curr.length() == n) {
        if(s.find(curr) == s.end()) {
            cout<<curr<<endl;
            return curr;
        }
        return "";
    }
    string s1 = generate_num(curr + '0', s, n);
    string s2 = generate_num(curr + '1', s, n);

    if(s1 == "") return s2;
    return s1;
}

string findDifferentBinaryString(vector<string>& nums) {
    unordered_set<string> s;
    for(string num : nums) s.insert(num);

    string ans = generate_num("", s, nums.size());
    return ans;
}


int main() {

    vector<string> nums = {
        "01", "10"
    };
    string ans = findDifferentBinaryString(nums);
    cout<<"\n\nans = "<<ans;
    return 0;
}
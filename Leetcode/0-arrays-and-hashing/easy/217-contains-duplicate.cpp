/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> s;
    for(int num : nums) {
        if(s.find(num) != s.end()) return true;
        s.insert(num);
    }
    return false;
}

int main() {
    return 0;
}
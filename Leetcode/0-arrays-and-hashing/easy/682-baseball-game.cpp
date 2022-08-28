/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> arr;

        for(string op : ops) {

            int n = arr.size();

            if(op == "+") { 
                arr.push_back(arr[n-1] + arr[n-2]);
            } else if(op == "D") {
                arr.push_back(arr[n-1] * 2);
            } else if(op == "C") {
                arr.pop_back();
            } else {
                arr.push_back(stoi(op));
            }
        }

        return accumulate(arr.begin(), arr.end(), 0);
    }
};
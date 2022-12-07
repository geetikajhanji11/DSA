/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int originalValue;
    string mappedValue;
    int index;
    Node(int og, string m, int i) {
        this->originalValue = og;
        this->mappedValue = m;
        this->index = i;
    }
};

class Solution {

    // {0,              1,          2}
    // {originalValue, mappedValue, index}
    static bool customSort(Node n1, Node n2) {
        if(n1.mappedValue == n2.mappedValue) {
            return n1.index < n2.index;
        }
        
        if(n1.mappedValue.length() == n2.mappedValue.length()) {
            return n1.mappedValue < n2.mappedValue; 
        }

        return n1.mappedValue.length() < n2.mappedValue.length();
    }

    string convert(int originalValue, vector<int> &mapping) {
        if(originalValue == 0) return to_string(mapping[0]);

        string mappedStr = "";
        while(originalValue > 0) {
            int rem = originalValue % 10;
            int x = mapping[rem];
            mappedStr += to_string(x);
            originalValue /= 10;
        }

        // remove end zeroes 
        while(mappedStr.size() > 1 && mappedStr[mappedStr.length()-1] == '0') {
            mappedStr.pop_back();
        }

        reverse(mappedStr.begin(), mappedStr.end());

        return mappedStr;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        
        // {originalValue, mappedValue, index}
        vector<Node> sortedNums;

        for(int i=0; i<nums.size(); i++) {
            sortedNums.push_back({nums[i], convert(nums[i], mapping), i});
        }

        sort(sortedNums.begin(), sortedNums.end(), customSort);

        vector<int> result;

        for(auto v : sortedNums) {
            result.push_back(v.originalValue);
        }

        return result;

    }
};
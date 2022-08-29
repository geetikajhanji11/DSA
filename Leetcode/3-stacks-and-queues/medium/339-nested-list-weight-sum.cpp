/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    NestedInteger() {}
    bool isInteger() {}
    int getInteger() {}
    vector<NestedInteger> getList() {}
};

class Solution {
public:

    int dfs(vector<NestedInteger> nestedList, int depth) {
        int result = 0;
        for(NestedInteger curr : nestedList) {
            if(curr.isInteger()) {
                result += (depth * curr.getInteger());
            } else {
                result += dfs(curr.getList(), depth + 1);
            }
        }
        return result;
    }

    int depthSum(vector<NestedInteger> nestedList) {
        return dfs(nestedList, 1);
    }
};
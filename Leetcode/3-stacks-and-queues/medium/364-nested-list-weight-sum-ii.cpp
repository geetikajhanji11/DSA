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

// ************* MY SOLUTION *************
// NOT TESTED BUT SEEMS GOOD
// BELOW IS ANOTHER SOLUTION I FOUND ONLINE
class Solution {
public:

    // sum, depth
    pair<int, int> dfs(vector<NestedInteger> nestedList) {
        
        int result = 0;
        int depth = 1;

        for(NestedInteger curr : nestedList) {
            if(curr.isInteger()) {
                result += curr.getInteger();
            } else {
                auto p = dfs(curr.getList());
                depth = max(depth, p.second);
                result += p.first;
            }
        }

        return {result * depth, depth + 1};
    }

    int depthSumInverse(vector<NestedInteger> nestedList) {
        return dfs(nestedList).first;
    }
};

// ************* ONLINE SOLUTION *************
class Solution {
public:

    int getHeight(vector<NestedInteger> nestedList) {
        int height = 1;
        for (NestedInteger curr : nestedList) {
            if (!curr.isInteger()) {
                int tmp = getHeight(curr.getList());
                height = max(height, tmp + 1);
            }
        }
        return height;
    }

    int dfs(vector<NestedInteger> nestedList, int depth) {
        int result = 0;
        for(NestedInteger curr : nestedList) {
            if(curr.isInteger()) {
                result += (depth * curr.getInteger());
            } else {
                result += dfs(curr.getList(), depth - 1);
            }
        }
        return result;
    }

    int depthSumInverse(vector<NestedInteger> nestedList) {
        int height = getHeight(nestedList);
        return dfs(nestedList, height);
    }
};


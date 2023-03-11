/*******************************************************************
 mirror of:
    6 => 9
    9 => 6
    0 => 0
    1 => 1
    8 => 8
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    void dfs(int n, string curr, bool &isOdd, vector<string> &result) {

        if(n == 0) {

            // take mirror image of curr
            string revCurr = curr;
            reverse(revCurr.begin(), revCurr.end());
            for(int i=0; i<revCurr.length(); i++) {
                char ch = revCurr[i];
                if(ch == '6') revCurr[i] = '9'; 
                if(ch == '9') revCurr[i] = '6';
            }

            // extra char in between curr & revCurr
            // can be only that which is its own mirror (0,1,8)
            if(isOdd) {
                result.push_back(curr + "0" + revCurr);
                result.push_back(curr + "1" + revCurr);
                result.push_back(curr + "8" + revCurr);
            } else {
                result.push_back(curr + revCurr);
            }
            return;
        }

        // number cannot start with 0
        if(curr.length() > 0) dfs(n-1, curr + "0", isOdd, result);

        dfs(n-1, curr + "1", isOdd, result);
        dfs(n-1, curr + "8", isOdd, result);
        dfs(n-1, curr + "6", isOdd, result); 
        dfs(n-1, curr + "9", isOdd, result); 

    }


public:
    vector<string> findStrobogrammatic(int n) {
        if(n == 1) return {"0", "1", "8"};
        if(n == 2) return {"11", "69", "88", "96"};

        vector<string> result;
        bool isOdd = n % 2 != 0;
        
        dfs(n/2, "", isOdd, result);

        return result;
    }
};
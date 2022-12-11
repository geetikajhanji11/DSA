/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************ NEETCODE ************
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result;
        result.push_back({1});
 
        for(int i=1; i<numRows; i++) {
            int idx1 = -1;
            int idx2 = 0;

            vector<int> currRow;
            
            while(idx1 != result[i-1].size()) {
                int num1 = (idx1 == -1) ? 0 : result[i-1][idx1];
                int num2 = (idx2 == result[i-1].size()) ? 0 : result[i-1][idx2];
                int num = num1 + num2;
                currRow.push_back(num);
                idx1++;
                idx2++;
            } 

            result.push_back(currRow);
        }

        return result;
    }
};

// ************ MY SOLUTION ************ 
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> result(numRows);
        result[0] = {1};
 
        for(int i=1; i<numRows; i++) {
            vector<int> row;
            row.push_back(1);
            for(int j=1; j<result[i-1].size(); j++) {
                int num = result[i-1][j-1] + result[i-1][j];
                row.push_back(num);
            }
            row.push_back(1);
            result[i] = row;
        }

        return result;
    }
};
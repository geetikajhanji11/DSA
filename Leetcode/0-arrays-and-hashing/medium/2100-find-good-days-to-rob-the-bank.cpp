/*******************************************************************

security => 5,3,3,3,5,6,2
nonInc =>   0 1 2 3 0 0 1 
nonDec =>   0 4 3 2 1 0 0 

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    vector<int> getNonIncreasing(vector<int>& security) {
        int n = security.size();
        vector<int> nonInc(n, 0);
        
        nonInc[0] = 0;
        for(int i=1; i<security.size(); i++) {
            if(security[i] <= security[i-1]) {
                nonInc[i] = 1 + nonInc[i-1];
            } else {
                nonInc[i] = 0;
            }
        }
            
        return nonInc;
    }

    vector<int> getNonDecreasing(vector<int>& security) {
        int n = security.size();
        vector<int> nonDec(n, 0);

        nonDec[n-1] = 0;
        for(int i=n-2; i>=0; i--) {
            if(security[i] <= security[i+1]) {
                nonDec[i] = 1 + nonDec[i+1];
            } else {
                nonDec[i] = 0;
            }
        }

        return nonDec;
    }

public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();

        // base case 
        int size = n - (2 * time);
        if(size <= 0) return {};

        // main logic
        vector<int> nonInc = getNonIncreasing(security);
        vector<int> nonDec = getNonDecreasing(security);

        vector<int> result;
        for(int i=time; i < (n - time); i++) {
            if(nonInc[i] >= time && nonDec[i] >= time) {
                result.push_back(i);
            }
        }

        return result;
    }   
};
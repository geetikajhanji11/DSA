/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int sum_m = accumulate(rolls.begin(), rolls.end(), 0);
        int m = rolls.size();

        int sum_n = (mean * (n + m)) - sum_m; 

        if(n * 1 <= sum_n && sum_n <= n * 6) {

            // now find n numbers [1,6] that sum upto sum_n
            vector<int> result;
            while(sum_n != 0) {

                // select dice in a way such that 
                // sum_n is never less than n
                int dice = min(sum_n - n + 1, 6);
                result.push_back(dice);
                sum_n -= dice;
                n--;
            }
            
            return result;
        }

        return {};

    }
};
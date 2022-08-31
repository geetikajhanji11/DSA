/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);

        for(int i=2; i<=rowIndex; i++) {
            int prevRowSize = i;

            int prev = row[0];
            for(int j=1; j<prevRowSize; j++) {
                int temp = row[j];
                row[j] = row[j] + prev;
                prev = temp;
            }

        }

        return row;
    }
};
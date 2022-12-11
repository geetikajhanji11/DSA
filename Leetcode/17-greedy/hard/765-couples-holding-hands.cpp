/*******************************************************************
0-1,        5-4,        6-7,        3-2
even-odd    odd-even    even-odd    odd-even
odd=e+1     even=o-1    odd=e+1     even=o-1
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        unordered_map<int, int> index;
        for(int i=0; i<row.size(); i++) {
            index[row[i]] = i;
        }

        int swaps = 0;
        for(int i=0; i<row.size(); i=i+2) {
            
            // couple - person1
            int person1 = row[i];

            // couple - person2
            // calculation inferred from observation
            int person2;
            if(person1 % 2 == 0) person2 = person1 + 1;
            else person2 = person1 - 1;

            // person sitting next to person1 
            // is called person3
            int person3 = row[i+1];

            // correct person is sitting 
            if(person3 == person2) continue;

            // exchange seats
            int idx2 = index[person2];
            int idx3 = index[person3];

            swap(row[idx2], row[idx3]);

            index[person2] = idx3;
            index[person3] = idx2; 

            swaps++;
        }

        return swaps;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool canFormGroup(int groups, vector<int>& grades) {

        // basically = (n * (n + 1)) / 2
        int students = groups % 2 == 0 ? (groups / 2) * (groups + 1) : groups * ((groups + 1) / 2); 
        return students <= grades.size();
    }

public:
    int maximumGroups(vector<int>& grades) {

        int low = 1;
        int high = grades.size() - 1;

        int result = 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(canFormGroup(mid, grades)) {
                result = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return result;
    }
};
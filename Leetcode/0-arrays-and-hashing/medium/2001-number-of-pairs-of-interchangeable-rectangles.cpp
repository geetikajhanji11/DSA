/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        unordered_map<double, long long> count;

        for(auto rectangle : rectangles) {
            double width = rectangle[0];
            double height = rectangle[1];
            double ratio = width / height;
            count[ratio]++;
        }

        long long result = 0;
        for(auto rectangle : rectangles) {
            double width = rectangle[0];
            double height = rectangle[1];
            double ratio = width / height;

            result += count[ratio] - 1;
            count[ratio]--;
        }

        return result;
    }
};

int main() {

    return 0;
}
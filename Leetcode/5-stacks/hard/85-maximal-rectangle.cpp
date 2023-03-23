/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int largestRectangleInHistogram(vector<int> &nums) {
        int n = nums.size();

        stack<pair<int, int>> s; // num, index till where it can extend back

        int largestRectangle = 0;
        for(int i=0; i<n; i++) {

            if(nums[i] == 0) {
                while(!s.empty()) {
                    int currArea = s.top().first * (i - s.top().second);
                    largestRectangle = max(largestRectangle, currArea);
                    s.pop();
                }
                continue;
            }

            int lastPoppedIndex = -1;
            while(!s.empty() && s.top().first > nums[i]) {
                lastPoppedIndex = s.top().second;
                int currArea = s.top().first * (i - s.top().second);
                largestRectangle = max(largestRectangle, currArea);
                s.pop();
            }

            if(lastPoppedIndex != -1) {
                s.push({nums[i], lastPoppedIndex});
            } else {
                s.push({nums[i], i});
            }
        }

        while(!s.empty()) {
            int currArea = s.top().first * (n - s.top().second);
            largestRectangle = max(largestRectangle, currArea);
            s.pop();
        }

        return largestRectangle;
    }

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int cols = matrix[0].size();
        vector<int> dpRow(cols, 0);

        int largestRectangle = 0;
        for(int i=0; i<matrix.size(); i++) {

            // for current row
            for(int j=0; j<cols; j++) {

                
                if(matrix[i][j] == '1') {
                    if(i - 1 >= 0 && matrix[i-1][j] == '1') {
                        dpRow[j] += 1;
                    } else {
                        dpRow[j] = 1;
                    } 
                } else {
                    dpRow[j] = 0;
                }

            }

            int currRectangle = largestRectangleInHistogram(dpRow);
            largestRectangle = max(largestRectangle, currRectangle);

        }

        return largestRectangle;
    }
};
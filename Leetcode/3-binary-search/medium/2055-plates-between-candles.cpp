/*******************************************************************
Find out indices of candles and add them to a list
For each query [a, b]
find out the candles after a and the candles before b.

// candle index from original string "s"
1.  possible plates between the two extreme candles
    possiblePlates = (rightCandleIdx - leftCandleIdx + 1) - 2

// idx from new "candleIndexes" array
2.  candles in between the two extreme candles 
    candlesInBetween = (rightIdx - leftIdx + 1) - 2;

// total plates within the range
3.  total plates in the range
    totalPlates = possiblePlates - candlesInBetween
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    pair<int, int> binarySearch(vector<int> &candleIndexes, int target, bool isLeft) {
        int low = 0;
        int high = candleIndexes.size() - 1;

        int candleIdx = -1;
        int idx = -1;

        while(low <= high) {
            int mid = (low + high) / 2;
            if(candleIndexes[mid] == target) return {mid, target};
            else if(candleIndexes[mid] > target) {
                if(isLeft) {
                    candleIdx = candleIndexes[mid];
                    idx = mid;
                }
                high = mid - 1;
            } else {
                if(!isLeft) {
                    candleIdx = candleIndexes[mid];
                    idx = mid;
                }
                low = mid + 1;
            }
        }

        return {idx, candleIdx};
    }

public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candleIndexes;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == '|') {
                candleIndexes.push_back(i);
            }
        }

        vector<int> result;
        for(auto query : queries) {
            int leftRange = query[0];
            int rightRange = query[1];

            auto left = binarySearch(candleIndexes, leftRange, true);
            int leftIdx = left.first;
            int leftCandleIdx = left.second;

            auto right = binarySearch(candleIndexes, rightRange, false);
            int rightIdx = right.first;
            int rightCandleIdx = right.second;

            int candlesInBetween = rightIdx - leftIdx - 1;
            int totalPlates = (rightCandleIdx - leftCandleIdx + 1) - 2 - candlesInBetween;

            if(totalPlates < 0 || leftRange == rightRange) totalPlates = 0;
            result.push_back(totalPlates);
            
        }
        return result;
    }
};
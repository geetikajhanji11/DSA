/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();

        int low = 0;
        int high = n - 1;

        while(low <= high) {
            int mid = (low + high) / 2;

            // found direct answer
            if(citations[mid] == n - mid) {
                return citations[mid];
            } 
            
            // invalid, search for lower number
            else if(citations[mid] > n - mid) {
                high = mid - 1;
            }

            // valid, search for higher number
            else if(citations[mid] < n - mid) {
                low = mid + 1;
            }
        }

        return n - low;
    }
};
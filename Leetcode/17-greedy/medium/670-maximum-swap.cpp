/*******************************************************************
9834 = 9843
12345 = 52341
7645 = 7654
76455 = 76554
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// DISCUSS SOLUTION O(n)
class Solution {
public:
  int maximumSwap(int num) {
        string numstr = to_string(num);

        int maxidx = -1; int maxdigit = -1;
        int leftidx = -1; int rightidx = -1;        

        for(int i=numstr.size()-1; i>=0; i--) {

            // current digit is the largest by far
            if (numstr[i] > maxdigit) {
                maxdigit = numstr[i];
                maxidx = i;
                continue;
            }

            // best candidate for max swap if there is no more 
            // such situation on the left side
            if (numstr[i] < maxdigit) {
                leftidx = i;
                rightidx = maxidx;
            }
        }

        // num is already in order
        if (leftidx == -1) return num;

        swap(numstr[leftidx], numstr[rightidx]);

        return stoi(numstr);
    }
};

// MY SOLUTION O(nlogn)
class Solution {
public:
    int maximumSwap(int num) {

        string numString = to_string(num);

        string sortedNumString = numString;
        sort(sortedNumString.begin(), sortedNumString.end(), greater<char>());

        int swap_i = -1;
        for(int i=0; i<numString.length(); i++) {
            if(sortedNumString[i] != numString[i]) {
                swap_i = i;
                break;
            }
        }

        if(swap_i == -1) return num;
        char swap_ch = sortedNumString[swap_i];

        int swap_j = -1;
        for(int j=numString.length(); j>=0; j--) {
            if(numString[j] == swap_ch) {
                swap_j = j;
                break;
            }
        }

        swap(numString[swap_i], numString[swap_j]);

        return stoi(numString);
    }
};
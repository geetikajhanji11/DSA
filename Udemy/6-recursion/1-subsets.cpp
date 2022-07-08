/**************************************************************

https://www.youtube.com/watch?v=REOH22Xwdkk&ab_channel=NeetCode

SUBSETS

Given a string, find all subsets of the given string.
There are 2^n subsets of vector having n elements

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;


void findSubsets(vector<string> &subsets, string currStr, string givenStr, int i) {

    // base case
    if(i == givenStr.length()) {
        subsets.push_back(currStr);
        return;
    }

    // either include current index character
    findSubsets(subsets, currStr + givenStr[i], givenStr, i + 1);

    // or exclude it
    findSubsets(subsets, currStr, givenStr, i + 1);
}


// main function 
int main() {

    string givenStr = "abc";
    vector<string> subsets;
    string currStr = "";
    int i = 0;
    findSubsets(subsets, currStr, givenStr, i);

    for(int i=0; i<subsets.size(); i++) {
        cout<<i+1<<": "<<subsets[i]<<endl;
    }
    
}
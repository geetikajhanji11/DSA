#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
using namespace std;

/*

Implement a function that takes in two non-empty arrays
of integers, finds the pair of numbers (one from each
array) whose absolute difference is closest to zero,
and returns a pair containing these two numbers, with
the first number from array. Only one such pair will exist
for the test.

*/

pair<int,int> minDifference(vector<int> a,vector<int> b) {
    
    int minDiff = INT_MAX;
    pair<int, int> p;

    // soritng both arrays
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    // creating two pointers
    // one for each array
    int ptr_a = 0;
    int ptr_b = 0;

    // comparing arrays
    while(ptr_a != a.size() && ptr_b != b.size()) {
        int currDiff = abs(a[ptr_a] - b[ptr_b]);
        if(currDiff < minDiff) {
            minDiff = currDiff;
            p.first = a[ptr_a];
            p.second = b[ptr_b];
        } 
        if(a[ptr_a] < b[ptr_b]) {
            ptr_a++;
        } else {
            ptr_b++;
        }
    }
    return p;
}

// main function
int main() {

    vector<int> arr1{23, 5, 10, 17, 30};
    vector<int> arr2{26, 134, 135, 14, 19};

    auto p = minDifference(arr1, arr2);

    cout<<"\nPair: "<<p.first<<", "<<p.second;

    return 0;
}


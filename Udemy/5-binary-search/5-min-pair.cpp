/**************************************************************

MIN PAIR

Given two non-empty arrays, find the pair of numbers (one from
each array) whose absolute difference is minimum. Print any
one pair with the smallest difference.

Input:
    a1 = {-1, 5, 10, 20, 3};
    a2 = {26, 134, 135, 15, 17};

Output:
    {17, 20}

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

// ------------ APPROACH - 1 -------------------
pair<int, int> minPair(vector<int> a1, vector<int> a2) {

    // sorting any 1 array
    sort(a1.begin(), a1.end());

    // helper variables 
    int minDiff = INT_MAX;
    pair<int, int> p;

    // iterate over 1 array and look for 
    // closest elements in other array
    for(int num2 : a2) {

        // in sorted array
        // lb has index of element >= x
        // lb-1 has index of element < x
        auto rightIdx = lower_bound(a1.begin(), a1.end(), num2) - a1.begin();
        auto leftIdx = rightIdx - 1;

        int rightDiff = abs(num2 - a1[rightIdx]);
        int leftDiff = abs(num2 - a1[leftIdx]);

        if(rightDiff < leftDiff && rightDiff < minDiff) {
            minDiff = rightDiff;
            p.first = num2;
            p.second = a1[rightIdx];
        }

        if(leftDiff < rightDiff && leftDiff < minDiff) {
            minDiff = leftDiff;
            p.first = num2;
            p.second = a1[leftIdx];
        }
        
    }

    return p;

}

// ------------ APPROACH - 2 -------------------
pair<int, int> minPair(vector<int> a1, vector<int> a2) {

    // sorting both arrays
    sort(a1.begin(), a1.end());
    sort(a2.begin(), a2.end());

    int i = 0;
    int j = 0;

    int min_diff = INT_MAX;
    int x = INT_MAX;
    int y = INT_MAX;

    while(i < a1.size() && j < a2.size()) {

        int diff = abs(a1[i] - a2[j]);
        if(diff < min_diff) {
            min_diff = diff;
            x = a1[i];
            y = a2[j];
        }

        if(a1[i] <= a2[j]) i++;
        else j++;
    }

    return {x, y};
}

// main function
int main() {

    vector<int> a1{-1, 5, 10, 20, 3};
    vector<int> a2{26, 134, 135, 15, 17};
    
    auto p = minPair(a1, a2);
    cout<<"\n\nAmswer: "<<p.first<<", "<<p.second;

}









/*
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

pair<int, int> minPair(vector<int> a1, vector<int> a2) {

    // sorting any 1 array
    sort(a1.begin(), a1.end());

    // helper variables 
    int minDiff = INT_MAX;
    pair<int, int> p;
    
    // iterating through unsorted array 2
    for(int num2 : a2) {

        // apply binary search on sorted a1 array
        // by choosing each element from a2.
        // we try to use binary search to find
        // number in a1 which is as close to num2 of a2
        int low = 0;
        int high = a1.size() - 1;
        while(low <= high) {    
            int mid = (low + high) / 2;
            int diff = abs(a1[mid] - num2);

            if(diff < minDiff) {
                minDiff = diff;
                p.first = a1[mid];
                p.second = num2;
            }

            if(a1[mid] < num2) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

    }

    return p;

}

// main function
int main() {

    vector<int> a1{-1, 5, 10, 20, 3};
    vector<int> a2{26, 134, 135, 15, 17};
    
    auto p = minPair(a1, a2);
    cout<<p.first<<", "<<p.second;

}

*/
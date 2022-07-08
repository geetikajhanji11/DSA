/**************************************************************

SORTING SUBARRAY
SAME AS SUBARRAY SORT IN 
SECTION-2: ARRAYS AND VECTORS

Write a function that takes in an array and returns two integers, 
denoting starting and ending indices of the smallest subarray 
in the input array that needs to be sorted in place so that the
entire input is sorted.

If the input array is already sorted, return a pair [-1.-1]

Input:
    {0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29}

Output:
    {4, 6}

Explanation:
    If we sort the subarray [10, 11, 7] then entire array becomes sorted.


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

// Expected Optimal Complexity O(n) Time, O(1) Space
// may be start with O(NLogN) and try to improve
// complete this function

// O(NlogN) => copy array to temp array and sort it.
// Compare the elements one by one and find first
// mismatch from left and first mismatch from right

// O(N)
pair<int,int> subarraySorting(vector<int> a){
    
    int smallest = INT_MAX;
    int largest = INT_MIN;

    // finding smallest and largest
    for(int i=0, j=a.size()-1; i<a.size()-1; i++, j--) {
        // inconsistency
        if(a[i] > a[i+1]) {
            smallest = min(smallest, a[i+1]);
        }
        // inconsistency
        if(a[j] < a[j-1]) {
            largest = max(largest, a[j-1]);
        }
    }

    if(smallest == INT_MAX && largest == INT_MIN) {
        return {-1, -1};
    }

    // find actual position
    int i = 0;
    int j = a.size() - 1;

    int idx_smallest = -1;
    int idx_largest = -1;
    while(idx_smallest == -1 || idx_largest == -1) {
        if(idx_smallest == -1 && a[i] > smallest) {
            idx_smallest = i;
        }
        if(idx_largest == -1 && a[j] < largest) {
            idx_largest = j;
        }
        i++;
        j--;
    }
    
    
    return {idx_smallest, idx_largest};
}

// main function
int main() {

    vector<int> a{0, 2, 4, 7, 10, 11, 7, 12, 13, 14, 16, 19, 29};
    auto p = subarraySorting(a);
    cout<<"\nSubarray Index: "<<p.first<<", "<<p.second;

    return 0;

}
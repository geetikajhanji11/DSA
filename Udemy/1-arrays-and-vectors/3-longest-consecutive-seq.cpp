#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*

LONGEST CONSECUTIVE SEQUENCE

Given an array containing n integers, find the length
of the longest band.

A band is defined as a subsequence which can be reordered
in such a manner all elements appear consecutive (i.e, 
with absolute difference of 1 between neighbouring 
elements)

A longest band is the band (subsequence) which contains
maximum integers
*/

// O(n)
int longestBand(vector<int> arr) {
    int result = 0;

    // inserting all elements
    // in a hash set
    unordered_set<int> hashSet;
    for(int num : arr) {
        hashSet.insert(num);
    }

    for(int num : arr) {
        // current num does not have left neighbour
        // means it is START of subsequence
        if(hashSet.find(num-1) == hashSet.end()) { // O(1)
            int count = 1;
            int nextNum = num + 1;
            while(hashSet.find(nextNum) != hashSet.end()) {
                count++;
                nextNum++;
            }
            result = max(result, count);
        }
    }

    return result;
}


int main() {

    vector<int> arr {1, 9, 3, 0, 18, 5, 2, 4, 10, 7, 12, 6};
	
    int result = longestBand(arr);
    cout<<"Answer = "<<result;

    return 0;
}

/**************************************************************

https://www.youtube.com/watch?v=nIVW4P8b1VA&ab_channel=NeetCode

ROTATED MINIMUM

Find Minimum in Rotated Sorted Array

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

// keep going to unsorted part of array
int rotatedSearchMinimum(vector<int> arr) {

    int low = 0;
    int high = arr.size()-1;

    if(arr[low] < arr[high]) return arr[0];

    while(low <= high) {

        int mid = (low + high) / 2;
        int left = mid - 1;
        int right = mid + 1;

        // found pivot
        if(arr[mid] <= arr[left] && arr[mid] <= arr[right] && left >= 0 && right < arr.size()) {
            return arr[mid];
        }

        // mid ... high
        // right part is sorted part
        // so move to left
        if(arr[mid] < arr[high]) {
            high = mid - 1;
        } 
        
        // mid ... high
        // arr[mid] >= arr[high]
        // right part is unsorted
        // so go right only
        else {
            low = low + 1;
        }
    }

    return -1;
}

// main function
int main() {

    vector<int> arr{100, 11, 12, 13, 14, 15};

    int minimum = rotatedSearchMinimum(arr);
    cout<<"\nMinimum element = "<<minimum;

}
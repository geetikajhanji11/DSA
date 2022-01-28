/**************************************************************

https://www.youtube.com/watch?v=4sQL7R5ySUU&ab_channel=NeetCode

Given an array in sorted order, find the frequency of an
element key in the array.
(Find the first and last position of element in sorted array)

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

int frequencyCount(vector<int> arr, int key) {

    // search left 
    // (first occurrence)
    int low = 0;
    int high = arr.size() - 1;
    int leftIdx = -1;

    // binary search
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            leftIdx = mid;
            high = mid - 1;
        } else if(arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    // search right 
    // (second occurrence)
    low = 0;
    high = high = arr.size() - 1;
    int rightIdx = -1;

    // binary search
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key) {
            rightIdx = mid;
            low = mid + 1;
        } else if(arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout<<"\nFirst occurence at index: "<<leftIdx;
    cout<<"\nLast occurence at index: "<<rightIdx;

    if(rightIdx == -1 && leftIdx == -1) return 0;

    return rightIdx - leftIdx + 1;
}

// main function
int main() {

    vector<int> arr{0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
    int key = 2;

    int count = frequencyCount(arr, key);
    cout<<"\nCount = "<<count;

}
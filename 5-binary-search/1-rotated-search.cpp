/**************************************************************

https://www.youtube.com/watch?v=U8XENwh8Oy8&ab_channel=NeetCode

ROTATED SEARCH

Write a function that takes input a sorted array of distinct
integers, which is rotated about a pivot point and finds
the index of any givne element.

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

int rotatedSearch(vector<int> arr, int key) {

    int low = 0;
    int high = arr.size()-1;

    while(low <= high) {

        int mid = (low + high) / 2;

        // found
        if(arr[mid] == key) {
            return mid;
        }

        // lies on line1
        if(arr[low] <= arr[mid]) {
            if(arr[low] <= key && key <= arr[mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        // lies on line2
        else if(arr[mid] <= arr[high]) {
            if(arr[mid] <= key && key <= arr[high]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    }

    return -1;
}

// main function
int main() {

    vector<int> arr{4, 5, 6, 7, 0, 1, 2, 3};
    int key = 3;

    int index = rotatedSearch(arr, key);
    cout<<"\nIndex of element = "<<index;

}
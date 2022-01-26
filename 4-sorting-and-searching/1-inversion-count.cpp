/**************************************************************

INVERSION COUNT

Given an array containing integers, you need to count the
total number of inversions.

Inversion => Two elements a[i] and a[j] form an inversion
if a[i] > a[j] and i < j

Input: 
    [0, 5, 2, 3, 1]

Output:
    5

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

int merge(vector<int> &arr, int l, int r) {

    int count = 0;

    vector<int> temp(r+1);
    // arr1 =>  l      ...    mid
    // arr2 =>  mid+1  ...    r

    int mid = (l + r) / 2;
    int i = l;
    int j = mid+1;

    int k = 0;

    // merging
    while(i <= mid && j <= r) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            // here a[i] > a[j] and i < j
            // so increase count
            count += (mid - i) + 1;
            temp[k] = arr[j];
            j++;
        }
        k++;
    } 

    // copy remaining elements 
    // from arr1 to temp array
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    } 

    // copy remaining elements 
    // from arr2 to temp array
    while(j <= r) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // replace original array
    // with temp array
    k = 0;
    for(int idx=l; idx<=r; idx++) {
        arr[idx] = temp[k];
        k++;
    }

    return count;
}

int countInversions(vector<int> &arr, int l, int r) {
    
    // base case for recursion
    // if only 1 element is present
    if(l >= r) {
        return 0;
    }

    int mid = (l + r) / 2;
    int leftCount = countInversions(arr, l, mid);
    int rightCount = countInversions(arr, mid+1, r);
    int crossCount = merge(arr, l, r);
    return leftCount + rightCount + crossCount;
}

// main function
int main() {

    vector<int> arr{0, 5, 2, 3, 1};
    int inversions = countInversions(arr, 0, arr.size()-1);
    cout<<"\nInversions = "<<inversions;

    return 0;

}
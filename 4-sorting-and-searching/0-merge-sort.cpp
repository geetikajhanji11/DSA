/**************************************************************

MERGE SORT

For linked list =>
https://www.youtube.com/watch?v=TGveA1oFhrc&ab_channel=NeetCode

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

void merge(vector<int> &arr, int l, int r) {

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
}

void mergeSort(vector<int> &arr, int l, int r) {
    
    // base case for recursion
    // if only 1 element is present
    if(l >= r) {
        return;
    }

    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, r);
}



// main function
int main() {

    vector<int> arr{10, 2, -2, 5, 0, 7, 6, 4, 8};
    mergeSort(arr, 0, arr.size()-1);

    for(int num : arr) {
        cout<<num<<" ";
    }

    return 0;

}
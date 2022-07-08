/**************************************************************

QUICK SORT
Also look => https://www.youtube.com/watch?v=4xbWSRZHqac&t=643s&ab_channel=NeetCode

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

// returns index of sorted element
int partition(vector<int> &arr, int l, int r) {
    int pivot = arr[r];

    int low = l;
    int high = r-1;

    while(low <= high) {
        while(low <= high && arr[low] < pivot) {
            low++;
        }
        while(low <= high && arr[high] > pivot) {
            high--;
        } 
        if(low < high) {
            int temp = arr[low];
            arr[low] = arr[high];
            arr[high] = temp;
        }
    }
    int temp = arr[r];
    arr[r] = arr[low];
    arr[low] = temp;

    return low;

}

// rescursive function
void quickSort(vector<int> &arr, int l, int r) {

    // base case
    if(l >= r) {
        return;
    }

    // recursive case
    int j = partition(arr, l, r);
    quickSort(arr, l, j-1);
    quickSort(arr, j+1, r);
    
}

// main function
int main() {

    vector<int> arr{0, -1, 10, -10, 5, 2, 3, 4};

    quickSort(arr, 0, arr.size()-1);
    cout<<"\nArray\n";
    for(int num : arr) {
        cout<<num<<" ";
    }

    return 0;

}
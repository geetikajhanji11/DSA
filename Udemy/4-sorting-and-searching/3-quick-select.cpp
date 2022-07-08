/**************************************************************

QUICK SELECT

Average Case - O(n)
Worst Case - O(n^2)

Write a function that takes input an array of distinct integers,
and returns kth smallest in the array

Also look kth LARGEST ELEMENT => https://www.youtube.com/watch?v=XEmy13g1Qxc&t=221s&ab_channel=NeetCode

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
int quickSelect(vector<int> &arr, int l, int r, int k) {

    // assume k will be inside the array
    int j = partition(arr, l, r);

    if(j == k) {
        return arr[j];
    }
    
    else if(j < k) {
        return quickSelect(arr, j+1, r, k);
    } 
    
    else {
        return quickSelect(arr, l, j-1, k);
    } 
    
    

}

// main function
int main() {

    vector<int> arr{10, 5, 2, 0, 7, 6, 4};
    
    for(int k=1; k<=arr.size(); k++) {
        
        int kthSmallest = quickSelect(arr, 0, arr.size()-1, k-1);
        cout<<"\n"<<k<<"th smallest = "<<kthSmallest;
    }
    
    return 0;

}
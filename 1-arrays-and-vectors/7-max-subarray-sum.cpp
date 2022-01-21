#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
using namespace std;

/*

Implement a function that takes vector of ints
and prints maximum subarray sum that can be formed.

*/

void printMaxSubarray(vector<int> arr, int startIndex, int maxSum) {
    cout<<"\nStart Index = "<<startIndex;
    cout<<"\nSubarray: ";
    while(maxSum != 0) {
        cout<<arr[startIndex]<<" ";
        maxSum -= arr[startIndex];
        startIndex++;
    }
}

int maxSubarraySum(vector<int> arr){
    
    int n = arr.size();

    int maxSum = 0;
    int maxSoFar = 0;
    int startIndex = 0;

    for(int i=0; i<n; i++) {

        int num = arr[i];
        maxSoFar += num;

        if(maxSoFar < 0) {
            maxSoFar = 0;
            startIndex = i + 1;
        }

        maxSum = max(maxSum, maxSoFar);
    }

    if(maxSum != 0) {
        printMaxSubarray(arr, startIndex, maxSum);
    }
    
    
    return maxSum;
}

// main function
int main() {

    vector<int> arr{-1, 2, 3, 4, -2, 6, -8, 3};

    int sum = maxSubarraySum(arr);
    cout<<"\nMax sum = "<<sum;

    return 0;
}


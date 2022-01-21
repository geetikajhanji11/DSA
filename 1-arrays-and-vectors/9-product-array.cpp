#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
using namespace std;

/*

https://www.youtube.com/watch?v=bNvIQI2wAjk&ab_channel=NeetCode

Implement a function that takes in vector of integers,
and returns a vector of the same length, where each
element in the output array is equal to the product 
of every other number in the input array. Solve this problem without using division.

Sample Input:
    {1, 2, 3, 4, 5}

Sample Output:
    {120, 60, 40, 30, 24}

*/

//Expected Complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    // finding the prefix array
    vector<int> prefix(n, 1);
    for(int i=1; i<n; i++) {
        prefix[i] = prefix[i-1] * arr[i-1];
    }

    // finding the postfix array
    vector<int> postfix(n, 1);
    for(int i=n-2; i>=0; i--) {
        postfix[i] = postfix[i+1] * arr[i+1];
    }

    // multiplying ith of prefix and postfix
    // to get final output array
    for(int i=0; i<n; i++) {
        output[i] = prefix[i] * postfix[i];
    }
    
    return output;
}

// main function
int main() {

    vector<int> arr{1, 2, 3, 4, 5};

    vector<int> result = productArray(arr);
    cout<<"\nProduct Array: ";
    for(int num : result) {
        cout<<num<<" ";
    }

    return 0;
}


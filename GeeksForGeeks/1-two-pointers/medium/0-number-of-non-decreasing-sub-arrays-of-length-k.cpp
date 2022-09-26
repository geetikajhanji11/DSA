/*******************************************************************
If subarrayLength = 1; arr[i..j] is not strictly increasing, 
then subarrays after it , i.e.,

arr[i...j+1], arr[i...j+2], .... arr[i...n-1]

cannot be strictly increasing
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** SOLUTION - 1 ***********
// O(M) where M = number of valid subarrays  
int countIncreasing(vector<int> arr) {
    int ctr = 0;

    // Pick starting point
    for (int i=0; i<arr.size(); i++) {

        // Pick ending point
        for (int j=i+1; j<arr.size(); j++) {
            if (arr[j] > arr[j-1]) ctr++;
            else break;
        }
    }
     
    return ctr;
}

// *********** SOLUTION - 2 ***********
// O(N) BETTER
int countIncreasing(vector<int> arr) {
    int ctr = 0;
    int subarrayLength = 1;
    
    for (int i=0; i<arr.size()-1; i++) {

        if(arr[i] < arr[i+1]) {
            subarrayLength++;
        } else {
            ctr += ((subarrayLength - 1) * subarrayLength) / 2;
            subarrayLength = 1;
        }
    }

    if(subarrayLength > 1) {
        ctr += ((subarrayLength - 1) * subarrayLength) / 2;
    }
     
    return ctr;
}

int main() {
  vector<int> arr = {1, 2, 2, 4};
  cout << "Count of strictly increasing subarrays is "<< countIncreasing(arr);
  return 0;
}
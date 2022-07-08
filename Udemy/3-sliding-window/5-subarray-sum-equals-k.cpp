/**************************************************************

https://www.youtube.com/watch?v=fFVZt-6sgyo&t=474s&ab_channel=NeetCode

Given an unsorted array of integers, find the number of 
subarrays haaving sum exactly equal to a fiven number k.

input:
    arr = {10, 2, -2, -20, 10}
    k = -10

output:
    3

10 + 2 + -2 + -20 = 10
-20 + 10 = -10
2 + -2 + -20 + 10 = -10

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

int cntSubarrays(vector<int> arr, int k) {
    
    unordered_map<int, int> mp;
    mp[0] = 1;
    
    int result = 0;
    int sum = 0;

    for(int i=0; i<arr.size(); i++) {
        sum += arr[i];

        int prefixSum = sum - k;

        if(mp.find(prefixSum) != mp.end()) {
            result += mp[prefixSum];
        } 

        mp[sum]++;
        
    }
    
    return result;
    
}


// main function
int main() {

    vector<int> arr{10, 2, -2, -20, 10};
    int k = -10;

    int result = cntSubarrays(arr, k);
    cout<<"\nSubarrays = "<<result;

    return 0;

}
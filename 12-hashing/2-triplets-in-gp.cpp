/******************************************************************************

TRIPLETS IN GP

Given an array, count the number of triplets with indices (i, j, k) such
that the elements at those indices are in geometric progression for a
given common ratio r and such that i < j < k.

Input: 
    arr = {1, 16, 4, 16, 64, 16}
    r = 4
    
Output: 
    3

Explanation:
    {1, 4, 16}
    {1, 4, 16}
    {4, 16, 64}
    

*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

int tripletsInGP(vector<int> arr, int r) {
    
    unordered_map<int, int> leftMap;
    unordered_map<int, int> rightMap;
    
    // every element in left map has frequency 0
    // every element in right map has frequency in entire array
    for(int num : arr) {
        rightMap[num]++;
        leftMap[num] = 0;
    }
    
    // logic
    int count = 0;
    for(int num : arr) {
        
        // remove num from right map
        rightMap[num]--;
        
        // count frequency of a/r in left map
        // count frequency of a*r in right map
        // only if a/r exists
        if(num % r == 0) {
            int a = num / r;
            int b = num;
            int c = num * r;
            
            // update count
            count += (leftMap[a] * rightMap[c]);
        }
        
        // add num to left map
        leftMap[num]++;
    }
    
    return count;
    
}

int main() {
    
    vector<int> arr{1, 16, 4, 16, 64, 16};
    int r = 4;
    int result = tripletsInGP(arr, r);
    cout<<result;
    
    return 0;
}

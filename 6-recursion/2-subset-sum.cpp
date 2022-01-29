/**************************************************************

https://www.youtube.com/watch?v=REOH22Xwdkk&ab_channel=NeetCode

SUBSET SUM

Given a set of non-negative integers, and a value sum,
determine if there is a subset of the given set with
sum equal to given sum.

Input:
    arr = {10, 12, 15, 6, 19, 20, 1}
    sum = 16

Output:
    Yes, 2 subsets [10, 6] and [15, 1]

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


void findSubsetSum(vector<vector<int>> &subsets, vector<int> curr, vector<int> arr, int currSum, int targetSum, int i) {

    // base cases
    if(currSum == targetSum) {
        subsets.push_back(curr);
        return;
    }
    if(i == arr.size()) {
        return;
    }

    // either include num at ith index
    // and update sum
    curr.push_back(arr[i]);
    findSubsetSum(subsets, curr, arr, currSum + arr[i], targetSum, i + 1);

    // or exclude it
    // dont update sum
    curr.pop_back();
    findSubsetSum(subsets, curr, arr, currSum, targetSum, i + 1);
}


// main function 
int main() {
    vector<vector<int>> subsets;
    vector<int> curr;
    vector<int> arr{10, 12, 15, 6, 19, 20, 1};
    int currSum = 0;
    int targetSum = 16;
    
    findSubsetSum(subsets, curr, arr, currSum, targetSum, 0);

    for(int i=0; i<subsets.size(); i++) {
        for(int num : subsets[i]) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    
}




/********** If we want only the NUMBER os subsets and not the subsets themselves


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


void findSubsetSum(vector<int> arr, int currSum, int targetSum, int i, int &answer) {

    // base cases
    if(currSum == targetSum) {
        answer++;
        return;
    }
    if(i == arr.size()) {
        return;
    }

    // either include num at ith index
    // and update sum
    findSubsetSum(arr, currSum + arr[i], targetSum, i + 1, answer);

    // or exclude it
    // dont update sum
    findSubsetSum(arr, currSum, targetSum, i + 1, answer);
}


// main function 
int main() {

    vector<int> arr{1, 2, 3, 4, 5};
    int targetSum = 6;
    int currSum = 0;
    int answer = 0;
    
    findSubsetSum(arr, currSum, targetSum, 0, answer);

    cout<<answer;
    
}

*/
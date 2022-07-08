/******************************************************************************

LONGEST K-SUM SUBARRAY

You are given an array, find out the length of the longest subarray
whose sum is equal to given integer k.

Input: 
    arr = {0, -2, 1, 2, 3, 4, 5, 15, 10, 5}
    k = 15
    
Output: 
    4
    
Explanation:
    1, 2, 3, 4, 5
    
*******************************************************************************/
#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int longestSubarrayKSum(vector<int> arr,int k){
    
    int n = arr.size();
	unordered_map<int,int> m;
	
	int prefix = 0;
	int len = 0;

	for(int i=0;i<n;i++){
		prefix += arr[i];

		if(prefix == k) {
			len = max(len,i+1);
		}

		if(m.find(prefix-k)!=m.end()){
			len = max(len,i - m[prefix-k]);
		}
		else{
			//store the first occ
			m[prefix] = i;
		}

	}
	return len;
    
}

int main() {
    
    vector<int> arr{0, -2, 1, 2, 3, 4, 5, 15, 10, 5};
    int k = 15;
    int result = longestSubarrayKSum(arr, k);
    cout<<result;
    
    
    return 0;
}

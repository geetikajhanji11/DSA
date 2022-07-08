#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*

MY SOLUTION

Given an array of size >= 2, find the smallest
subarray that needs to be sorted in pace so that
entire input array becomes sorted.

If input array is already sorted, the function
should return [-1, 1], otherwise return the start and end
index of smallest subarray

*/

bool outOfOrder(vector<int> arr,int i){
	int x = arr[i];
	if(i==0){
		return x > arr[1];
	}
	if(i==arr.size()-1){
		return x < arr[i-1];
	}
	return x > arr[i+1] || x < arr[i-1];

}

vector<int> subarraySort(vector<int> arr) {

	int smallest = INT_MAX;
	int largest = INT_MIN;

	for(int i=0;i<arr.size();i++){
		int x = arr[i];
		
		if(outOfOrder(arr,i)) {
			smallest = min(smallest,x);
			largest = max(largest,x);
		}
	}

	//next step find the right index where smallest and largest lie (subarray) for out solution
	if(smallest==INT_MAX){
		return {-1,-1};
	}

	int left = 0;
	while(smallest >= arr[left]){
		left++;
	}
	int right = arr.size() - 1;
	while(largest <= arr[right]){
		right--;
	}

	return {left,right};

}

// main function
int main() {

    vector<int> arr {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};

    auto result = subarraySort(arr);

    for(int i : result) {
        cout<<i<<", ";
    }
	
    return 0;
}

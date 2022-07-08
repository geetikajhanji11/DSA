#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// given an array of distinct integers
// return length of highest mountain

// a amountain is defined as adjacent integers that are
// strictly increasing until they reach a peak, at which they 
// become strictly decreasing

// at least 3 numbers are required to make a mountain

int mountain(vector<int> arr) {

    int result = 0;

    for(int i=1; i<arr.size()-1; i++) {
        
        // if we found a peak
        if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
            int currCount = 1;
            
            // counting back elements
            int left = i;
            while(arr[left] > arr[left-1] && left >= 1) {
                currCount++;
                left--;
            }

            // counting forward elements
            int right = i;
            while(arr[right] > arr[right+1] && right < arr.size()-1) {
                currCount++;
                right++;
            }
            result = max(currCount, result);
            i = right;
        } 
        
    }

    return result;
}


int main() {

    vector<int> arr {5,6,1,2,3,4,5,4,3,2,0,1,2,3,-2,4};
	// vector<int> arr {5,6,1,7};

    int result = mountain(arr);
    cout<<"result = "<<result;

    return 0;
}

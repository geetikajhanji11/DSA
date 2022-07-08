#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

// given an array containing n integers, and a target, find 3 distinct integers that can pair up to form target sum. 

vector<vector<int>> threeSum(vector<int> arr, int target){
    
    vector<vector<int>> result;

    sort(arr.begin(), arr.end()); // nlogn

    int prev = arr[0];

    for(int i=0; i<arr.size()-2; i++) { // n^2

        // handling duplicates
        if(i != 0 && arr[i] == prev) continue;
        prev = arr[i];

        // calculate twoSum
        int twoSum = target - arr[i];

        // two pointer approach
        int left = i + 1;
        int right = arr.size() - 1;
        while(left < right) {

            // handling duplicates
            if(arr[left] == arr[right]) break;

            // calculating sum
            int sum = arr[left] + arr[right];

            if(sum == twoSum) {

                // found triplet
                result.push_back({arr[i], arr[left], arr[right]});
                
                // changing left pointer while handling duplicates
                if(left < right && arr[left] == arr[left+1]) {
                    while(left < right && arr[left] == arr[left+1]) left++;
                } else {
                    left++;
                }

                // changing right pointer while handling duplicates
                if(left < right && arr[right] == arr[right-1]) {
                    while(left < right && arr[right] == arr[right-1]) right--;
                } else {
                    right--;
                }
                
            } 
            
            // changing left pointer while handling duplicates
            else if(sum < twoSum) {
                if(left < right && arr[left] == arr[left+1]) {
                    while(left < right && arr[left] == arr[left+1]) left++;
                } else {
                    left++;
                }
                
            } 
            
            // changing right pointer while handling duplicates
            else {
                if(left < right && arr[right] == arr[right-1]) {
                    while(left < right && arr[right] == arr[right-1]) right--;
                } else {
                    right--;
                }
                
            }
        }
    }

    return result;
    
}

int main() {

    vector<int> arr {1, 1, 2, 2, 2, 3, 4, 5, 6, 7, 7, 7, 8, 9, 15};
	int target = 18;

    auto result = threeSum(arr, target);
    for(vector<int> triplet : result) {
        for(int num : triplet) {
            cout<<num<<", ";
        }
        cout<<endl;
    }

    return 0;
}

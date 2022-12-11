/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    int closest_index = 0;
    int diff = INT_MAX;

    int low = 0;
    int high = arr.size() - 1;

    while(low <= high) {
        int mid = (low + high) / 2;
        if(abs(arr[mid] - x) < diff) {
            closest_index = mid; 
            diff = abs(arr[mid] - x);
        }

        if(arr[mid] == x) break;
        if(x < arr[mid]) high = mid - 1;
        else low = mid + 1;
    }

    cout<<"i: "<<closest_index;

    int left = closest_index - 1;
    int right = closest_index + 1;
    int n = arr.size();
    k -= 1;

    while(k != 0) {
        int left_diff = left >= 0 ? abs(x - arr[left]) : INT_MAX;
        int right_diff = right < n ? abs(x - arr[right]): INT_MAX;
        if(left_diff <= right_diff) {
            left--;
            k--;
        } else if(right_diff < left_diff) {
            right++;
            k--;
        }
    }

    vector<int> result;
    for(int i=left+1; i<=right-1; i++) {
        result.push_back(arr[i]);
    }

    return result;
} 

int main() {

    vector<int> arr = {1,2,8,10,30};
    int x = 15;
    int k = 3;
    auto res = findClosestElements(arr, k, x);
    for(int num : res) cout<<num<<", ";
    return 0;
}
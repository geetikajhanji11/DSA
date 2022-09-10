/*******************************************************************

*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

// Function to return the missing element
int findMissing(vector<int> arr){
    int n = arr.size();

    int low = 0;
    int high = n - 1;

    while(low < high) {
        int mid = (low + high) / 2;

        // mid is consecutive, 
        // missing number must lie somewhere right
        if(arr[mid] - mid == arr[0]) {
            // check if the next element is consistent
            if(arr[mid+1] - arr[mid] > 1) return arr[mid] + 1;
            else low = mid + 1;
        }

        // mid is not consecutive,
        // missing number must lie somewhere left
        else {
            // check is the prev element is consistent
            if(mid > 0 && (arr[mid] - arr[mid-1] > 1)) return arr[mid] - 1;
            else high = mid - 1;
        }
    }

    return -1;
}

// Driver code
int main() {
	vector<int> arr = { -9, -8, -7, -5, -4, -3, -2, -1, 0 };
	cout<<findMissing(arr);
}

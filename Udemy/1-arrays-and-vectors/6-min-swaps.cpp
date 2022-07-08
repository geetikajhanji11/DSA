#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

/*

Given an array of size n, find the minimum 
number of swaps needed to make the array as
sorted.
*/

int minSwaps(vector<int> arr) {
    int result = 0;

    int n = arr.size();

    // know the actual positions of elements
    // store the current indices
    pair<int, int> ap[n];
    for(int i=0; i<n; i++) {
        ap[i].first = arr[i];
        ap[i].second = i;
    }

    // sorting
    sort(ap, ap + n);

    // visited array
    vector<bool> visited(n, false);

    // main logic
    for(int i=0; i<n; i++) {

        int old_position = ap[i].second;
        int new_position = i;

        // if element is visited or 
        // element is in right place
        if(old_position == new_position || visited[new_position]) {
            continue;
        }

        // visiting the element (index)
        // for first time
        int node = i;
        int cycle = 0;
        while(!visited[node]) {
            visited[node] = true;
            int next_node = ap[node].second;
            node = next_node;
            cycle++; 
        }

        result += cycle-1;
        
    }
    return result;
}


int main() {

    vector<int> arr {10, 11, 5, 4, 3, 2, 1};

    int result = minSwaps(arr);
    cout<<"Minimum Swaps = "<<result;
	
    return 0;
}

/*******************************************************************
https://www.geeksforgeeks.org/chocolate-distribution-problem/

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int chocolate_distribution(vector<int> packets, int m) {

    sort(packets.begin(), packets.end());

    int left = 0;
    int right = m-1;

    int min_difference = INT_MAX;

    while(right < packets.size()) {
        int diff = packets[right] - packets[left];
        min_difference = min(diff, min_difference);
        left = left + 1;
        right = right + 1;
    }

    return min_difference;
}

int main() {

    cout<<chocolate_distribution({7, 3, 2, 4, 9, 12, 56}, 3)<<endl;
    cout<<chocolate_distribution({3, 4, 1, 9, 56, 7, 9, 12}, 5)<<endl;
    cout<<chocolate_distribution({12, 4, 7, 9, 2, 23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50}, 7)<<endl;

    return 0;
}
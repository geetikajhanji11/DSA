/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> replaceElements(vector<int>& arr) {

    int n = arr.size();
    int greatest = arr[n-1];
    arr[n-1] = -1;

    for(int i=n-2; i>=0; i--) {
        int temp = arr[i];
        arr[i] = greatest;
        greatest = max(greatest, temp);
    }

    return arr;
}

int main() {

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> temp = nums1;

    int i = 0;
    int j = 0;
    int k = 0;
    
    while(i < m && j < n) {
        if(temp[i] <= nums2[j]) {
            nums1[k] = temp[i];
            i++;
        } else {
            nums1[k] = nums2[j];
            j++;
        }
        k++;
    }

    while(i < m) {
        nums1[k] = temp[i];
        i++;
        k++;
    }

    while(j < n) {
        nums1[k] = nums2[j];
        j++;
        k++;
    }
    
}

int main() {

    return 0;
}
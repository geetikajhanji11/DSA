/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height) {
    int n = height.size();

    int left = 0;
    int right = n-1;

    int largest_area = 0;

    while(left < right) {
        int h1 = height[left];
        int h2 = height[right];
        
        int width = right - left;
        int height = h1 < h2 ? h1 : h2;
        int area = width * height;

        largest_area = max(largest_area, area);
        
        if(h1 < h2) left++;
        else right--;
    }
    return largest_area;
}

int main() {

    return 0;
}
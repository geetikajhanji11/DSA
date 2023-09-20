/*******************************************************************
    Idea / Proof:

1.  The widest container (using first and last line) is a good candidate, 
    because of its width. Its water level is the height of the smaller one 
    of first and last line.

2.  All other containers are less wide and thus would need a higher 
    water level in order to hold more water.

3.  The smaller one of first and last line doesn't support a higher 
    water level and can thus be safely removed from further consideration.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int ans = 0;
        while(left < right) {
            int area = (right - left) * min(height[left], height[right]);
            ans = max(area, ans);

            if(height[left] > height[right]) right--;
            else left++;
        }      

        return ans;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        // area of two rectangles
        int areaSquare1 = (ax2 - ax1) * (ay2 - ay1);
        int areaSquare2 = (bx2 - bx1) * (by2 - by1);

        // bottom left portion of overlap
        // (cx1, cy1)
        int cx1 = max(ax1, bx1);
        int cy1 = max(ay1, by1);

        // top right portion of overlap
        // (cx2, cy2)
        int cx2 = min(ax2, bx2);
        int cy2 = min(ay2, by2);

        // area of overlap
        int overlap = 0;
        if(cx2 > cx1 && cy2 > cy1) {
            overlap = (cx2 - cx1) * (cy2 - cy1);
        }

        return areaSquare1 + areaSquare2 - overlap;
    }
};
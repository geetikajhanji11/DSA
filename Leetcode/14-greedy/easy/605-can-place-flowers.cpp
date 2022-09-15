/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    bool inBounds(int i, vector<int>& flowerbed) {
        return i >= 0 && i < flowerbed.size();
    }

public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i=0; i<flowerbed.size(); i++) {

            if(n == 0) break;
            if(flowerbed[i] == 1) continue;

            if(i == 0) {
                if(!inBounds(i+1, flowerbed) || flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                } 
            }

            else if(i == flowerbed.size()-1) {
                if(!inBounds(i-1, flowerbed) || flowerbed[i-1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
            }

            else if(i-1 >= 0 && flowerbed[i-1] == 0 && i+1 < flowerbed.size() && flowerbed[i+1] == 0) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};
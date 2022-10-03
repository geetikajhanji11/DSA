/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string pushDominoes(string dominoes) {
        
        int n = dominoes.size();
        // handle edge cases for first "L/R" and last "L/R"

        // first "L/R"
        int left = 0;
        int right = 0;
        while(left < n && dominoes[left] == '.') left++;

        // make all left
        if(left < n && dominoes[left] == 'L') {
            int l = left - 1;
            while(l >= 0) {
                dominoes[l] = 'L';
                l--;
            }
        }

        // traverse whole string
        while(right < n) {

            // ******** find next "L/R" ********
            right++;
            while(right < n && dominoes[right] == '.') right++;
            if(right == n) break;

            // all middle dots won't be affected
            if(dominoes[left] == 'L' && dominoes[right] == 'R') {
                // do nothing
            }

            // the middlemost dot will remain a dot only
            // rest left dots will be R
            // rest right dots will be L
            // "RRRR.LLLL" or "RRLL"
            else if(dominoes[left] == 'R' && dominoes[right] == 'L') {
                int l = left;
                int r = right;
                while(l < r) {
                    dominoes[l] = 'R';
                    dominoes[r] = 'L';
                    l++;
                    r--;
                }
            }

            // middle dots will be R
            else if(dominoes[left] == 'R' && dominoes[right] == 'R') {
                int l = left;
                int r = right;
                while(l <= r) {
                    dominoes[l] = 'R';
                    dominoes[r] = 'R';
                    l++;
                    r--;
                }
            }

            // middle dots will be L
            else if(dominoes[left] == 'L' && dominoes[right] == 'L') {
                int l = left;
                int r = right;
                while(l <= r) {
                    dominoes[l] = 'L';
                    dominoes[r] = 'L';
                    l++;
                    r--;
                }
            }
            
            left = right;
        }

        // make all right
        if(left < n && dominoes[left] == 'R') {
            int r = left + 1;
            while(r < n) {
                dominoes[r] = 'R';
                r++;
            }
        }

        return dominoes;
    }
};
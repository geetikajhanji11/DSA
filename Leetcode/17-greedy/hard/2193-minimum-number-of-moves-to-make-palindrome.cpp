/*******************************************************************
Keep the left half of string fixed nd try to adjust the
right half of the string
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int n = s.length();

        int left = 0;
        int right = n - 1;
        int minSwaps = 0;

        while(left < right) {

            int l = left;
            int r = right;

            while(s[l] != s[r]) r--;

            // l == r means single occurence of character
            // this will be the middle element at the end
            if(l == r) {
                swap(s[r], s[r+1]);
                minSwaps++;
                continue;
            } 
            
            // swapping adjacent characters
            // up until we reach right
            else {
                while(r < right) {
                    swap(s[r], s[r+1]);
                    minSwaps++;
                    r++;
                }
            }

            left++;
            right--;
        }
        
        return minSwaps;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(logN)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low = 0;
        int high = letters.size() - 1;

        char ans = 'z' + 1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(letters[mid] > target) {
                ans = letters[mid];
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        if(ans == 'z' + 1) return letters[0];
        return ans;
    }
};

// O(N)
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if(target == 'z') return letters[0];

        char upperBound = 'z' + 1;

        for(char letter : letters) {
            if(letter > target && letter < upperBound) {
                upperBound = letter;

            }
        }

        if(upperBound == 'z' + 1) return letters[0];

        return upperBound;
    }
};
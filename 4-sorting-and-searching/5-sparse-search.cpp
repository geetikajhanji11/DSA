/**************************************************************

SPARSE SEARCH

Given a sorted array of strings that is interspersed with
empty strings, write a method to find the location of a 
given string

Input:
    arr = {"ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""}
    word = "bat"

Output: 
    4
**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;


int sparseSearch(vector<string> strs, string word) {

    int low = 0;
    int high = strs.size() - 1;

    while(low <= high) {

        int mid = (low + high) / 2;

        if(strs[mid] == "") {

            int left = mid - 1;
            int right = mid + 1;

            while(true) {
               
               if(left < low && right > high) {
                   return -1;
               } else if(right <= high && strs[right] != "") {
                   mid = right;
                   break;
               } else if(left >= low && strs[left] != "") {
                   mid = left;
                   break;
               }
                left--;
                right++;
            }

        }

        if(strs[mid] == word) {
            return mid;
        } 

        else if(strs[mid] < word) {
            low = mid + 1;
        }

        else if(strs[mid] > word) {
            high = mid - 1;
        }
    }

    return -1;

}

// main function
int main() {

    vector<string> strs {
        "ai", "", "", "bat", "", "", "car", "cat", "", "", "dog", ""
    };
    string word = "dog";

    int position = sparseSearch(strs, word);
    cout<<"\nPosition = "<<position;
    
    
    return 0;

}
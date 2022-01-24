/**************************************************************

Given a string, find the smallest window (substring) which 
contains all distinct characters of the given input string.

input:
    aabcbcdbcaaad
output:
    dbca

input:
    aaaa
output:
    a

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
#include<unordered_set>
using namespace std;

string smallestWindow(string str) {
    
    string result = "";
    
    if(str.length() == 0) return result;
    
    // create map for str to so we can
    // lookup the distinct chars in str
    unordered_map<char, int> mp_distinct;
    for(char ch : str) {
        mp_distinct[ch] = 1;
    }
    int totalDistinct = mp_distinct.size();

    // maintain a map for window
    unordered_map<char, int> mp_window;
    int left = 0;
    int right = 0;
    int count = 0;

    int start = 0;
    int end = 0;
    int diff = INT_MAX;

    // main loop
    while(right < str.length()) {

        // expand the window
        char right_ch = str[right];
        mp_window[right_ch]++;

        // increase count
        if(mp_distinct[right_ch] == 1) {
            count++;
            mp_distinct[right_ch] = 0;
        }

        if(count == totalDistinct) {
            
            // contract
            char left_ch = str[left];
            while(mp_window[left_ch] > 1) {
                mp_window[left_ch]--;
                left++;
                left_ch = str[left];
            }

            if(right - left < diff) {
                diff = right - left;
                start = left;
                end = right;
            }

        }

        // next iteration
        right++;
    }

    for(int i=start; i<=end; i++) {
        result.push_back(str[i]);
    }

    return result;
}



// main function
int main() {

    string str = "aabcbcdbcaaad";

    string result = smallestWindow(str);
    cout<<"\nAnswer = "<<result;

    return 0;

}
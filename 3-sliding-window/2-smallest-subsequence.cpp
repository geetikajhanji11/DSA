/**************************************************************

Given two strings, one big string and one small string,
find the "smallest window" in the big string that contains
all characters of the small string

=> window can have additional characters than required
=> if small string has duplicates, then those duplicates
    must be present with same or higher count in window

input:
    s1 = hello_world
    s2 = lol
output:
    llo

input:
    s1 = fizzbuzz
    s2 = fuzz
output:
    fizzbu

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

string smallestSubsequence(string str1, string str2) {

    // start and end are the indexes 
    // of the smallest final substring
    string result;
    int start = -1;
    int end = -1;

    int diff = INT_MAX;

    // frequency map for str2 (pattern)
    unordered_map<char, int> mp2;
    for(char ch : str2) {
        mp2[ch]++;
    } 

    // frequency map for str1 (string)
    unordered_map<char, int> mp1;
    int left = 0;
    int right = 0;

    // keeps track of how many chars
    // have been matched as of yet
    int count = 0;

    // main loop
    while(right < str1.length()) {

        // expand window
        char right_ch = str1[right];
        mp1[right_ch]++;

        // ch is present in mp2 and
        // freq count of ch in mp1 < mp2
        if(mp2.find(right_ch) != mp2.end() && mp1[right_ch] <= mp2[right_ch]) {
            count++;
        }
        
        // all characters have been matched
        if(count == str2.length()) {
            
            // remove unwanted characters
            // from left -> contract
            char left_ch = str1[left];
            while(mp1[left_ch] > mp2[left_ch] || mp2.find(left_ch) == mp2.end()) {
                mp1[left_ch]--;
                left++;
                left_ch = str1[left];
            }

            // check if window is small
            if(right - left < diff) {
                start = left;
                end = right;
                diff = right - left;
            }

        } 
        
        right++;
        
    }

    // creating the final smallest string
    for(int i=start; i<=end; i++) {
        result.push_back(str1[i]);
    }

    // return
    return str1.substr(start, end+1);
}



// main function
int main() {

    string str1 = "fizzbuzzaf";
    string str2 = "fuzz";

    string result = smallestSubsequence(str1, str2);
    cout<<"\nString: "<<result;

    return 0;

}
/******************************************************************************

ANAGRAMS IN SUBSTRINGS

Two strings are anagrams of each other if the letters of one string
can be rearranged to form the other string.
Given a string, find the number of pairs of substrings of the string
that are anagrams of each other.

Input: 
    abba
    
Output: 
    4
    
Explanation:
    [a, a]
    [ab, ba]
    [b, b]
    [abb, bba] 
    
*******************************************************************************/
#include<iostream>
#include<map>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

int anagramsInSubstrings(string input) {

    int n = input.length();
    map<vector<int>, int> mp;
    
    // creating substrings
    cout<<"\nSUBSTRINGS\n";
    for(int i=0; i<n; i++) {
        string s = "";
        for(int j=i; j<n; j++) {
            s.push_back(input[j]);
            cout<<s<<endl;
            
            vector<int> freq(26, 0);
            for(char ch : s) {
                int index = ch - 'a';
                freq[index]++;
            }
            mp[freq]++;
        }
    }
    
    // display map
    // calculate count
    // count = fC2 = (f * (f-1) / 2)
    int count = 0;
    cout<<"\nMAP\n";
    for(auto el : mp) {
        for(int i=0; i<3; i++) {
            cout<<el.first[i]<<" ";
        }
        cout<<": "<<el.second<<endl;
        if(el.second >= 2) {
            count += (el.second * (el.second - 1)) / 2;
        }
    } 
    
    return count;
    
}

int main() {
    
    string input = "abba";
    
    int result = anagramsInSubstrings(input);
    cout<<"\nNumber of anagrams in substrings: "<<result;
    
    return 0;
}

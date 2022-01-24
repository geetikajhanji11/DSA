#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;

/*

Given a string, write a function to find the largest
substring with unique characters (no duplicates)

input:
    prateekbhaiya
    aabcb

output:
    ekbhaiy
    abc

*/

string largestUniqueSubstring(string str) {

    string result;

    int window_length = 0;
    int i = 0;
    int j = 0;

    int left = 0;
    int right = 0;

    unordered_set<char> uniqueChars;

    while(right < str.length()) {

        // if we found another unique character,
        // include it in set
        if(uniqueChars.find(str[right]) == uniqueChars.end()) {
            cout<<"inserting "<<str[right]<<" in set...\n";
            uniqueChars.insert(str[right]);
            if((right - left + 1) >= window_length) {
                window_length = right - left + 1;
                cout<<"\n----> "<<left<<", "<<right<<endl;
                i = left;
                j = right;
            }
        } 
        
        // if there is already a character in set,
        // start deleting the chars from unique chars
        // upto right-1
        else {
            cout<<endl;
            while(str[left] != str[right]) {
                cout<<"removing "<<str[left]<<" from set...\n";
                uniqueChars.erase(uniqueChars.find(str[left]));
                left++;
            }
            left++;
            cout<<"WINDOW FROM "<<str[left]<<"["<<left<<"]"<<" ... "<<str[right]<<"["<<right<<"]"<<endl<<endl;
        }

        right++;
    }

    for( ; i<=j; i++) {
        result.push_back(str[i]);
    }

    return result;
}



// main function
int main() {

    string str = "prateekbhaiya";

    string result = largestUniqueSubstring(str);
    cout<<"\n\nString: "<<result;


    return 0;
}


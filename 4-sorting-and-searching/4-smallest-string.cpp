/**************************************************************

SMALLEST STRING

You're given a list of n strings, a1, a2, a3, ...., an.
You have to concatenate them together in some order such that
the resulting string would be lexicographically smallest.
Given the list of strings, output the lexicographically
smallest concatenation.

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


bool my_compare(string a, string b) {
    return a + b < b + a;
}


// main function
int main() {

    // vector<string> strs{
    //     "c", "cb", "cba"
    // };

    vector<string> strs{
        "a", "ab", "aba"
    };

    sort(strs.begin(), strs.end(), my_compare);

    for(string str : strs) {
        cout<<str;
    }
    
    return 0;

}
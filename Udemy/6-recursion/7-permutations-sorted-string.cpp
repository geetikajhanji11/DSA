/**************************************************************

SORTED PERMUTATIONS (STRING)

Sorted Permutations

Given a string S of lowercase alphabets, you need to find all ‘unique’ 
permutations of the string in a "sorted" order.

(Hint: You can use find all permutations using brute force, and put 
them in a set for the sorting.

Input:
    s = "abc"

Output:
    [
        "abc",
        "acb",
        "bac",
        "bca",
        "cab",
        "cba"
    ]

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
#include <set>
using namespace std;

void recur(set<string> &result, string curr, string s, vector<bool> visited) {

    if(curr.length() == s.length()) {
        result.insert(curr);
        return;
    }

    for(int i=0; i<s.length(); i++) {
        if(!visited[i]) {
            visited[i] = true;
            recur(result, curr + s[i], s, visited);
            visited[i] = false;
        }
    }
    
}

vector<string> findSortedPermutations(string s){
    set<string> result;
    vector<bool> visited(s.length(), 0);

    recur(result, "", s, visited);

    vector<string> uniquePermutations;

    for(auto itr = result.begin(); itr != result.end(); itr++) {
        uniquePermutations.push_back(*itr);
    }
    
    return uniquePermutations;
}

// main function 
int main() {
    
    string s = "abc";
    vector<string> result = findSortedPermutations(s);
    for(string str : result) {
        cout<<str<<endl;
    }

    return 0;
    
}
#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
using namespace std;

/*

Given a string, print all subsequences of the
string sorted by length and lexicographic sorted
order if length is same.

*/


bool my_compare(string s1, string s2) {
    
    int len1 = s1.length();
    int len2 = s2.length();

    // if same length,
    // lexicographic compare
    if(len1 == len2) {
        return s1 < s2;
    }
    
    // else length compare
    else return len1 < len2;
}

// recursive function
void subsequence(vector<string> &result, string curr, int i, string str) {

    // base case
    if(i == str.length()) {
        result.push_back(curr);
        return;
    }

    // recursive case
    curr.push_back(str[i]);
    subsequence(result, curr, i+1, str);
    curr.pop_back();
    subsequence(result, curr, i+1, str);

}

// target function
vector<string> sortedSubsequences(string str) {
    
    vector<string> result;
    string curr = "";
    int i = 0;
    subsequence(result, curr, i, str);

    // sorting according to length and lex
    sort(result.begin(), result.end(), my_compare);

    return result;
}

// main function
int main() {

    string str = "abcd";
    vector<string> result = sortedSubsequences(str);

    for(string s : result) {
        cout<<s<<endl;
    }

    return 0;
}


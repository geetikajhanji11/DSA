#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

/*

Given a palindromic string of lowercase English letters
palindrome, replace exactly one character with any lowercase
english letter so that the resulting string is not a palindrom 
and that it is lexicographically smallest one possible

input:
    abccba

output:
    aaccba

*/

string breakPalindrome(string palindrome) {

    int n = palindrome.length();
    if(n == 1) return "";

    int i = 0;
    for( ; i<n; i++) {
        if(palindrome[i] == 'a') continue;

        else if(i != n/2) {
            palindrome[i] = 'a';
            break;
        }
    }

    if(i == n) {
        palindrome[n-1] = 'b';
    } 

    return palindrome;
}


// main function
int main() {

    cout<<breakPalindrome("aa");

    return 0;
}


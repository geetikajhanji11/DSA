#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
using namespace std;

/*

Given 2 non-empty strings, write a function
that determines whether the second string
is subsequence of first one.

example:
    codingminutes
    cines

output:
    yes

*/

bool checkSubsequence(string str1, string str2) {

    int ptr1 = 0;
    int ptr2 = 0;

    while(ptr1 != str1.length()) {
        if(str1[ptr1] == str2[ptr2]) {
            ptr2++;
            if(ptr2 == str2.length()) {
                return true;
            }
        }
        ptr1++;
    }
    return false;
}

int main() {

    string str1 = "coding minutes";
    string str2 = "ctones";
    
    if(checkSubsequence(str1, str2)) {
        cout<<"YES";
    } else {
        cout<<"NO";
    }

    return 0;
}


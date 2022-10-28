/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// without string conversion
int divisorSubstrings(int num, int k) {
	int count = 0;
	int power = pow(10, k);
	
	// Process number from right to left, taking k digits in each iteration
	// At leftmost k digits, loop terminates because n / pow = 0
	for (int n = num; n > 0; n /= 10) {
		int divisor = n % power;
		if (divisor != 0 && num % divisor == 0) count++;

		// No digits to the left can contribute to divisor's size being k.
		if (n / power == 0) break;
	}

	return count;
}

// using string conversion
class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string str = to_string(num);
        int ctr = 0;
        
        string currString = str.substr(0, k);
        
        for(int i=k; i<=str.length(); i++) {

            int x = stoi(currString);
            if(x != 0 && num % x == 0) ctr++;
            
            if(i == str.length()) break;
            currString = currString.substr(1, k-1) + str[i];
            
        }

        return ctr;
    }
};
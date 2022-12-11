/*******************************************************************
We are doing this:
For n = 3

1.  Keep changing bits from the right to left (0th to nth bit)
    until we get a number that is not been visited

2.  Visit the number, i.e., put in set and make "num" as this
    new number

3.  Repeat 1 and 2 until result vector is full 

-------------------------------
        WALKTHROUGH
-------------------------------
START

000 
001 
011 [0th bit change = 000 already exists]
010 
110 [0th bit change => 011, 1st bit change => 000 already exists]
111
110 
100 [111 already exists]

STOP
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* BACKTRACKING *************
class Solution {
    vector<string> grayCodeForN(int n) {
        
        if(n == 1) return {"0", "1"};

        vector<string> smallerGrayCodes = grayCodeForN(n-1);
        vector<string> currGrayCodes;

        for(int i=0; i<smallerGrayCodes.size(); i++) {
            currGrayCodes.push_back("0" + smallerGrayCodes[i]);
        }

        for(int i=smallerGrayCodes.size()-1; i>=0; i--) {
            currGrayCodes.push_back("1" + smallerGrayCodes[i]);
        }

        return currGrayCodes;
    }

public:
    vector<int> grayCode(int n) {
        vector<string> resultStrings = grayCodeForN(n);
        vector<int> result;
        for(string binaryString : resultStrings) {
            result.push_back(stoi(binaryString, 0, 2));
        }
        return result;
    }
};

// ************* EASIER TO CODE *************
class Solution {
public:

   vector<int> grayCode(int n) {
        
        vector<int> result;
        result.push_back(0);

        for(int i=0; i<n; i++) {
            int size = result.size();
            for(int j=size-1; j>=0; j--) {
                int num = result[j] | 1<<i;
                result.push_back(num);
            }
        }

        return result;
    }
};

// ************* MY SOLUTION *************
// EXPLANATION IS ABOVE
class Solution {

    int getIthBit(int num, int i) {
        int mask = 1<<i;
        int x = mask & num;
        if(x == 0) return 0;
        return 1;
    }

    int setIthBit(int num, int i) {
        int mask = 1<<i;
        int ans = num | mask; 
        return ans;
    }

    int clearIthBit(int num, int i) {
        int mask = ~(1<<i);
        int ans = num & mask;
        return ans;
    }


public:
    vector<int> grayCode(int n) {
        
        vector<int> result;
        unordered_set<int> s;

        int num = 0;
        int total = pow(2, n);

        result.push_back(0);
        s.insert(0);

        while(result.size() != total) {

            int i = 0;
            for(i; i<n; i++) {

                int bit = getIthBit(num, i);
                int nextNum;
                if(bit == 0) {
                    nextNum = setIthBit(num, i);
                } else {
                    nextNum = clearIthBit(num, i);
                }

                // if we already have encountered this number
                // try changing the next ith bit
                if(s.find(nextNum) != s.end()) {
                    continue;
                }

                // this is a new number, we insert in set 
                // and the result array
                // then set back i = 0 and num = nextNum
                s.insert(nextNum);
                result.push_back(nextNum);
                num = nextNum;
                i = 0;
            }

        }
        
        return result;

    }
};
 
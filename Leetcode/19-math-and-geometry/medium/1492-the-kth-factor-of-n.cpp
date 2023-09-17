/*******************************************************************
    O(N)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthFactor(int n, int k) {
        int i = 1;
        int ctr_k = 1;

        while(i <= n) {
            
            if(n % i == 0) {
                if(ctr_k == k) return i;
                ctr_k++;
            }

            i++;
            
        }    

        return -1;
    }
};

/*******************************************************************

*******************************************************************/

class Solution {
public:
    int kthFactor(int n, int k) {

        float root = sqrt(n);

        for (int i=1; i<root; i++) {
            if (n % i == 0 && --k == 0) return i;
        }

        for (int i=root; i>0; i--) {
            if (n % i == 0 && --k == 0) return n/i;
        }

        return -1;

    }
};
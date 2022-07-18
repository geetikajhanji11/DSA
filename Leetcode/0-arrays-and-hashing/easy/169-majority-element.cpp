/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
    int element = 0;
    int ctr = 0;

    for(int num : nums) {
        if(ctr == 0) {
            element = num;
            ctr++;
        } 
        else if(element == num) ctr++;
        else ctr--;
    }

    return element;
}

int main() {

    return 0;
}
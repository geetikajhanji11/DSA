/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int guess(int num) {
    return -1;
}

int guessNumber(int n) {

    int low = 1;
    int high = n;

    while(low <= high) {
        int mid = (low + high) / 2;
        int my_guess = guess(mid);
        if(my_guess == 0) return mid;
        else if(my_guess == -1) high = mid - 1;
        else low = mid + 1;
    }        
    return -1;
}

int main() {

    return 0;
}
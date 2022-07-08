/**************************************************************

SQUARE ROOT

Find square root of number N upto P places

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

float squareRoot(int n, int p) {

    float root = 0.0;

    // binary search for integer part
    int integerPart = 0;
    int low = 1;
    int high = n;
    while(low <= high) {
        int mid = (low + high) / 2;
        int square = mid * mid;
        
        // perfect square
        if(square == mid) return mid;

        // find highest value of "square" closer to n
        if(square < n) {
            integerPart = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    root += (float) integerPart;

    // linear search p times for decimal part
    float inc = 0.1;
    while(p != 0) {
        
        while(root * root < n) {
            root += inc;
        }
        root = root - inc;
        p--;
        inc = inc / 10.0;
    }

    return root;
}

// main function
int main() {

    int n = 10;
    int p = 3;
    float answer = squareRoot(n, p);
    cout<<"\nSquare Root: "<<answer;

}
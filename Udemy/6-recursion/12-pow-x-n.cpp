/**************************************************************

POW(x, n)

Implement pow(x, n), which calculates x raised to the power n 
(i.e., xn).

Example 1:
    Input: x = 2.00000, n = 10
    Output: 1024.00000

Example 2:
    Input: x = 2.10000, n = 3
    Output: 9.26100

Example 3:
    Input: x = 2.00000, n = -2
    Output: 0.25000
    Explanation: 2-2 = 1/22 = 1/4 = 0.25

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

long long int calc(int a, int b) {
    if(a == 0) return 0;
    if(b == 0) return 1;
    if(b == 1) return a;

    long long int num = calc(a, b/2);
    if(b % 2 == 0) {
        return num * num;
    } else {
        return num * num * a;
    }
}

long long int powerModulo(int a, int b) {

    long long int result = calc(a, b);
    if(b < 0) return 1 / result;
    return result;

}

// main function 
int main() {
    
    cout<<powerModulo(16, 3);

    return 0;
    
}
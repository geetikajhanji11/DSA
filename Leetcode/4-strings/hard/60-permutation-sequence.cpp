/*******************************************************************

n = 4, k = 9

// "1234"
// "1243"
// "1324"
// "1342"
// "1423"
// "1432"
// "2134"
// "2143"
// "2314"

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int factorial(int n) {
    int res = 1, i;
    for (i = 2; i <= n; i++)
        res *= i;
    return res;
}
string getPermutation(int n, int k) {

    int limit = n;
    int number_of_permutations = 0;
    string permutation = "";

    unordered_set<int> visited;

    while(permutation.length() != limit) {
        
        int fact = factorial(n-1);
        for(int i=1; i<=limit; i++) {
            if(visited.find(i) != visited.end()) continue;
            number_of_permutations += fact;

            if(k > number_of_permutations) {
                continue;
            } 

            else {
                permutation += to_string(i);
                visited.insert(i);
                number_of_permutations -= fact;
                break;
            }
        }
        n--;
    }
    return permutation;
}

int main() {

    cout<<endl<<getPermutation(3, 3);
    cout<<endl<<getPermutation(4, 9);
    cout<<endl<<getPermutation(3, 1);

    return 0;
}
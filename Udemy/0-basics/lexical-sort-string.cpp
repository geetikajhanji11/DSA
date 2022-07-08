#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
using namespace std;

bool my_compare(char a, char b) {
    return a < b;
}

int main() {

    string s = "kdsjwqbeaj";
    sort(s.begin(), s.end(), my_compare);
    cout<<s;

    return 0;
}


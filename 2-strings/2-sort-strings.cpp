#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
using namespace std;

/*

Given a list of "n" strings s0, s1, s2, ..., sn-1,
each consisting of digits and spaces, the number
of spaces is the same for each entry, the goal is
to implement a variation of a sort command.
None of the strings contains consecutive spaces.
Also, no strings starts with a space nor ends with
it. Spaces are used to divide string into columns,
which can be used as keys in comparisons.

The program has to support the required params:

1. key: integer denoting the column used as key
        in comparisons. The left-most column is
        demoted by 1.

2. reversed: boolean variable indicating whether to
             reverse the final output.

3. type: either lexicographic or numeric.

*/


int toInteger(string s) {
    int num = 0;
    int n = s.length()-1;
    int i = 0;
    while(i != s.length()) {
        int temp = s[i] - '0';
        num += temp * pow(10, n);
        n--;
        i++;
    }
    return num;
}

bool my_compare_lex(pair<string, string> ap, pair<string, string> bp)
{
    string a = ap.first;
    string b = bp.first;
    return a < b;
}

bool my_compare_numeric(pair<string, string> ap, pair<string, string> bp) {
    int a = toInteger(ap.first);
    int b = toInteger(bp.first);
    return a <= b;
}


vector<string> sortStrings(vector<string> strs, int key, bool reversed, string type) {

    vector<string> result;

    // generating (vp) vector of pair of 
    // the key column number and the 
    // corresponding row
    vector<pair<string, string>> vp;
    for(string str : strs) {
        stringstream buffer(str);
        int ctr = 0;
        string currNum;
        while(ctr != key) {
            getline(buffer, currNum, ' ');
            ctr++;
        }
        vp.push_back(make_pair(currNum, str));
    }

    // how sorting should be done
    if(type == "numeric") {
        sort(vp.begin(), vp.end(), my_compare_numeric);
    } else {
        sort(vp.begin(), vp.end(), my_compare_lex);
    }
    for(auto x : vp) {
        result.push_back(x.second);
    }

    // if output should be reversed
    if(reversed) {
        reverse(result.begin(), result.end());
    }

    return result;
}


int main() {

    vector<string> strs{
        "92 022 4",
        "82 12 90",
        "77 13 6"
    };

    vector<string> result = sortStrings(strs, 2, false, "numeric");
    for(string s : result) {
        cout<<s<<endl;
    }


    return 0;
}


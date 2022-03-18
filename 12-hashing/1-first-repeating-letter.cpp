/******************************************************************************

FIRST REPEATING LETTER

*******************************************************************************/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

char firstRepeatChar(string input) {
    
    char result = '\0';

    unordered_set<char> s;
    for(char ch : input) {
        if(s.find(ch) != s.end()) {
            return ch;
        } else {
            s.insert(ch);
        }
    }
    
    return result;
}

int main() {
    
    string input = "codingminutes";
    char result = firstRepeatChar(input);
    cout<<result;
    
    return 0;
}

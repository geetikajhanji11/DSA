#include <iostream>
#include <string> 
#include <vector>
using namespace std;

string urlify(string s) {
    
    // calculate spaces
    int spaces = 0;
    for(char ch : s) {
        if(ch == ' ') {
            spaces++;
        }
    }

    // index of last character of original s
    int left = s.length() - 1;

    int extraCharacters = spaces * 2;
    s.resize(s.length() + extraCharacters, ' ');

    // last index of new string with extra memory
    int right = s.length() - 1;

    // replacing spaces
    while(left != 0) {
        if(s[left] == ' ') {
            s[right] = '0';
            s[right-1] = '2';
            s[right-2] = '%';
            right = right - 3;
        } else {
            s[right] = s[left];
            right--;
        }
        left--;
    }

    return s;
}

int main() {

    
    string s = "hello world,  how are you?";
    string new_s = urlify(s);
    cout<<"\nurlify = "<<new_s;

    return 0;
}


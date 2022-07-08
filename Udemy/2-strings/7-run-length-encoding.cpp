#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

/*

input: bbbaaaadexxxxxx
output = b3a4d1e1x6

*/

//str is the input the string
string compressString(const string &str){   
    
    string encoded = "";

    char ch = str[0];
    int count = 0;

    for(int i=0; i<str.length(); i++) {
        if(str[i] == ch) {
            count++;
        } else {
            encoded += ch + to_string(count);
            ch = str[i];
            count = 1;
        }
    }
    encoded += ch + to_string(count);

    if(encoded.length() > str.length())
        return str;
    return encoded;
}

// main function
int main() {

    cout<<compressString("bbbaaaadexxxxxx");
    

    return 0;
}


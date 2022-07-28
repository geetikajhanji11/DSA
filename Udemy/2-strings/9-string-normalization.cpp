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

Write a function that returns a copy of this 
sentence where all the words:
=> start with a capital letter
=> rest of the letters are lower case. 

input:
    This is SO MUCH FUN!

output:
    This Is So Much Fun!

*/

string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it

    for(int i = 0; i<copy.length(); i++) {
        if(copy[i] == ' ') continue;
        copy[i] = toupper(copy[i]);
        i++;
        while(copy[i] != ' ' && i < copy.length()) {
            copy[i] = tolower(copy[i]);
            i++;
        }
    }

    return copy;
}


// main function
int main() {

    cout<<normalize("This is SO MUCH FUN!");

    return 0;
}


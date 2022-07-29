/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// "//../home/lmao/...../......./dir1///.././../me1/me2/../lol"
// "/home/lmao/...../me1/lol"

// "//.a/home/lmao/...../......./dir1///.././../me1/me2/../lol"
// "/.a/home/lmao/...../me1/lol"

string simplifyPath(string path) {
    stack<string> s;
    int n = path.length();

    for(int i=0; i<n; i++) {

        if(path[i] == '/') continue;

        if(path[i] == '.') {

            int j = i;
            while(j<n && path[j] != '/') j++;
            int length = j - i;

            // single dot (do nothing)
            if(length == 1) {

            }

            // double dot (pop from stack)
            else if(length == 2 && path[i] == '.' && path[i+1] == '.') {
                if(!s.empty()) s.pop();
            }

            // multiple dots (directory) => push to stack
            else {
                string directory = path.substr(i, length);
                s.push(directory);
            }

            i = j;
        }

        // it is a directory, 
        // push it to stack
        else {
            string directory = "";
            while(i<n && path[i] != '/') {
                directory += path[i];
                i++;
            }
            s.push(directory);
        }

    }

    // if stack is empty
    if(s.empty()) return "/";

    // buld new path with revserved stack elements
    vector<string> directories(s.size());
    int k = s.size() - 1;

    while(!s.empty()) {
        directories[k] = s.top();
        k--; 
        s.pop();
    }

    string result = "";
    for(string directory : directories) {
        result += "/" + directory;
    }

    return result;
}

int main() {

    string path = "//../home/lmao/...../......./dir1///.././../me1/me2/../lol";
    simplifyPath(path);
    return 0;
}
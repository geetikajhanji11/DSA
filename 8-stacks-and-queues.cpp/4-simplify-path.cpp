/**************************************************************

SIMPLIFY PATH

In this coding challenge, we will build a functionality for a 
command line tool. 
We want to write a function that takes in 2 non-empty string 
representing a valid Unix-shell path and returns a
simplified version of the path. The simplified path must be 
equivalent to the original path, that means it should point to 
same file/directory as the original path.

A path can be an absolute path, meaning that it starts at the 
root directory in a file system, or a relative path, meaning 
that it starts at the current directory in a file system. In a 
Unix-like Operating System, a path is bounded by the following 
rules:

© The root directory is represented by a / . This means that 
if a path start with /, it's an absolute path; if it doesn’t 
it's a relative path.

© The symbol / otherwise represent the directory separator. 
This means that the path /x/y is location of directory y 
inside directory x, which is itself located inside the root
directory.

© The symbol .. represents the parent directory. This means 
that accessing files or directories in  /x/y/..  is 
equivalent to accessing files or directories in /x

© They symbol . represents the current directory. This means 
that accessing files or directories in  /x/y/. is equivalent  to accessing files or directories in /x/y

The symbols / and . can be repeated sequentially without 
consequence; the symbol .. cannot, however repeating it 
sequentially means going further up in the parent directories. 

For example,  /x/y/2/././. and /x/y/z are equivalent.
For example,  /x/y/z/../../.. and /x/y/z aren't. 

The only exception is with the root directory: /../../. and / 
are equivalent because the root directory has no parent 
directory, which means repeated accessing parent directories 
does nothing.

Examples:

    Input: /a/./b/../../c/
    output: /c

    Input: /a/..
    output: /

    Input: /a///b
    output: /a/b

    Input: /a/../
    output: /

    Input: /../../../../../a
    output : /a

    Input: /a/./b/./c/./d/
    output: /a/b/c/d

    Input: /a/../.././../../.
    output: /


**************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

string simplifyPath(string path) {
   
    // if last character does not have /
    // then insert it 
    if(path[path.length() - 1] != '/') {
        path.push_back('/');
    }

    // variables
    stack<char> folders;
    int dots = 0;
    char folder = '-';

    // go through entire string
    for(int i=0; i<path.length(); i++) {
        
        if(path[i] == '.') {
            dots++;
            continue;
        }

        else if(path[i] == '/') {

            // path is "../"
            // go to parent directory=> pop
            if(dots == 2) {
                if(!folders.empty()) {
                    folders.pop();
                }
            }

            // path is "./"
            // do nothing. already in current directory
            else if(dots == 1) {}

            // dots = 0
            // push the folder in stack
            else {
                if(folder != '-') {
                    folders.push(folder);
                }
                    
            }

            // update dots and folder name
            // after encountering "/"
            dots = 0;
            folder = '-';
        }

        // encountered current folder
        // update variable
        else {
            folder = path[i];
        }
    }

    // no folder in stack, return root
    if(folders.empty()) return "/";

    // relative path
    // if the path starts with "../../" 
    // then we need "../../" in result
    // before the folders sequence
    string prefix = "";
    int i = 0;
    if(path[i] == '.') {
        while(path[i] == '.' || path[i] == '/') {
            prefix += path[i];
            i++;
        }
        prefix.pop_back();
    }

    // result string
    string result = "";
    while(!folders.empty()) {
        result += folders.top();
        result += '/';
        folders.pop();
    } 
    reverse(result.begin(), result.end());
    result = prefix + result;
   
    return result;
   
}


int main() {

    string path = "../x/y/../z/././w/a///../../c/./";
    string result = simplifyPath(path);

    cout<<"\nPath: "<<result;

	return 0;
}
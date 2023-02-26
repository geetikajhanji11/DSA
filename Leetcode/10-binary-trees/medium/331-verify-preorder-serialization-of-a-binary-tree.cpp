/*******************************************************************

"9,3,4,#,#,1,#,#,2,#,6,#,#"

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********************** DISCUSS SOLUTION ***********************

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stringstream ss(preorder);
        string curr;
        int nodes = 1;

        while(getline(ss, curr, ',')) {
            nodes--;
            if(nodes < 0) return false;
            if(curr != "#") nodes += 2;
        }

        return nodes == 0;
    }
};

// *********************** MY SOLUTION ***********************
class Node {
public:
    bool left;
    bool right;
    Node() {
        left = false;
        right = false;
    }
};

class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<Node> s;

        if(preorder[0] == '#' && preorder.length() == 1) return true;
        if(preorder[0] == '#') return false;

        int j = 0;
        while(j < preorder.length() && preorder[j] != ',') j++;
        s.push(Node());

        j++;
        for(int i=j; i<=preorder.length(); i=i+2) {

            while(i < preorder.length() && preorder[i] != ',') i++;
            i--;

            while(!s.empty() && s.top().left && s.top().right) {
                s.pop();
            }

            if(s.empty()) return false;

            // get last element
            Node top = s.top(); s.pop();
            
            if(preorder[i] == '#') {
                if(!top.left) {
                    top.left = true;
                    s.push(top); // insert in stack
                } else if(!top.right) {
                    top.right = true; // remove from stack
                } else {
                    return false;
                }
            } 
            
            else {
                if(!top.left) {
                    top.left = true;
                    s.push(top);
                    s.push(Node());
                } else if(!top.right) {
                    top.right = true;
                    s.push(top);
                    s.push(Node());
                } else {
                    while(!s.empty() && s.top().left && s.top().right) {
                        s.pop();
                    }
                    if(s.empty()) {
                        return false;
                    }
                    Node newTop = s.top(); s.pop();

                    if(!newTop.left) {
                        newTop.left = true;
                        s.push(newTop);
                        s.push(Node());
                    } else if(!newTop.right) {
                        newTop.right = true;
                        s.push(newTop);
                        s.push(Node());
                    }
                }
            }
        }

        while(!s.empty() && s.top().left && s.top().right) {
            s.pop();
        }
    
        return s.empty();
    }
};
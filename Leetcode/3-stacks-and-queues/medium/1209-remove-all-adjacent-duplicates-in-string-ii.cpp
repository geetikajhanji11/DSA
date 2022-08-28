/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    class Character {
        public:
        char val;
        int consecutiveCount;
        Character(char val, int count) {
            this->val = val;
            this->consecutiveCount = count;
        } 
    };

public:
    string removeDuplicates(string s, int k) {
        stack<Character> myStack;

        for(char ch : s) {
            if(!myStack.empty() && myStack.top().val == ch) {
                Character topCharacter = myStack.top();
                myStack.pop();
                myStack.push(Character(ch, topCharacter.consecutiveCount + 1));
                if(myStack.top().consecutiveCount == k) {
                    myStack.pop();
                }
            } else {
                myStack.push(Character(ch, 1));
            }
        }

        string result = "";
        while(!myStack.empty()) {
            Character topCharacter = myStack.top();
            string word(topCharacter.consecutiveCount, topCharacter.val);
            result = word + result;
            myStack.pop();
        }

        return result;
    }
};
/*******************************************************************
SIMILAR TO "NUMBER OF ATOMS"
*******************************************************************/



#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string decodeString(string s) {
        stack<char> myStack;

        for(int i=0; i<s.length(); i++) {

            if(s[i] == ']') {

                // get the word
                string word = "";
                while(myStack.top() != '[') {
                    word = myStack.top() + word;
                    myStack.pop();
                }
                myStack.pop(); // pop "["

                // get the count
                string countString = "";
                while(!myStack.empty() && isdigit(myStack.top())) {
                    countString = myStack.top() + countString;
                    myStack.pop();
                }

                // insert word * count back in stack
                int count = stoi(countString);
                while(count != 0) {
                    for(char ch : word) myStack.push(ch);
                    count--;
                }

            } else {
                myStack.push(s[i]);
            }
        }

        // stack in reverse order is the result
        string result = "";
        while(!myStack.empty()) {
            result = myStack.top() + result;
            myStack.pop();
        }

        return result;
    }
};


// ************* MY SOLUTION HEHE *************
// 100% acceptance hehe
class Solution {
public:

    string decodeString(string s) {

        string result = "";
        stack<string> myStack;

        for(int i=0; i<s.length(); i++) {

            if(myStack.empty() && isalpha(s[i])) {
                result += s[i];
            } 

            if(!myStack.empty() && isalpha(s[i])) {
                string word = "";
                while(isalpha(s[i])) {
                    word += s[i];
                    i++;
                }
                myStack.push(word);
                // i could be at "]" or digit, so do i--
                i--; 
            } 
        
            if(isdigit(s[i])) {
                string digitString = "";
                while(isdigit(s[i])) {
                    digitString += s[i]; 
                    i++;
                }    
                myStack.push(digitString);
                // "i" is at "[" so it is okay 
                // if it is skipped due to for loop's i++
            }

            if(s[i] == ']') {
                string word = "";
                while(!myStack.empty() && isalpha(myStack.top()[0])) {
                    word = myStack.top() + word;
                    myStack.pop();
                }

                int count = stoi(myStack.top());
                myStack.pop();
                string duplicatedWord = "";
                while(count != 0) {
                    duplicatedWord += word;
                    count--;
                }

                if(!myStack.empty()) {
                    myStack.push(duplicatedWord);
                } else {
                    result += duplicatedWord;
                }
                
            }

        } 

        return result;
    }
};
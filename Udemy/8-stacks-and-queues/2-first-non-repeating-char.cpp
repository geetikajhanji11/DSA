/**************************************************************

FIRST NON REPEATING CHARACTER

Given a stream of characters, find the first non-repeating 
character from stream. If for a current index, there is no such
character return '0' for that particular index.

Sample Input:
    str = "aabcbcd"

Sample Output:
    vector = ['a', '0', 'b', 'b', 'c', '0', 'd' ]

**************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

vector<char> FindFirstNonRepeatingCharacter(string S){

    // queue: to keep track of sequence of characters
    // map: to keep track of frequency of characters
    // vector: stores result
    queue<char> q;
    unordered_map<char, int> mp;
    vector<char> result;

    // loop
    for(char ch : S) {

        // step-1: update map
        mp[ch]++;

        // step-2: check frequency in map 
        if(mp[ch] == 1) {
            q.push(ch);
        }

        char front = q.front();
        if(mp[front] == 1) {
            result.push_back(front);
        }

        else {

            while(!q.empty()) {
                front = q.front();
                if(mp[front] == 1) {
                    result.push_back(front);
                    break;
                } else {
                    q.pop();
                }  
            }

            if(q.empty()) result.push_back('0');
        }
    }
    return result;
}


int main() {

    string str = "aaabbcdbbaac";
    vector<char> result = FindFirstNonRepeatingCharacter(str);

    for(char ch : result) {
        cout<<ch<<" ";
    }


	return 0;
}
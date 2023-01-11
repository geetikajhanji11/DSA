/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********** ONE PASS **********

class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();

        unordered_map<char, int> freqSecret;
        unordered_map<char, int> freqGuess;

        int bulls = 0;
        int cows = 0;
        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
            } else {


                if(freqSecret[guess[i]] > 0) {
                    cows++;
                    freqSecret[guess[i]]--;
                } else {
                    freqGuess[guess[i]]++;
                }

                if(freqGuess[secret[i]] > 0) {
                    cows++;
                    freqGuess[secret[i]]--;
                } else {
                    freqSecret[secret[i]]++;
                }


            } 
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

// ********** TWO PASS **********
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();

        unordered_map<char, int> freq;
        for(char ch : secret) freq[ch]++;

        int bulls = 0;
        for(int i=0; i<n; i++) {
            if(secret[i] == guess[i]) {
                bulls++;
                freq[secret[i]]--;
                guess[i] = 'x';
            }
        }

        int cows = 0;
        for(char ch : guess) {
            if(ch == 'x') continue;
            // cout<<ch<<" = "<<freq[ch]<<endl;
            if(freq[ch] > 0) {
                cows++;
                freq[ch]--;
            }
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};


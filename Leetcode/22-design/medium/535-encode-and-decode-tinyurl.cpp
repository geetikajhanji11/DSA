/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int ctr;
    unordered_map<string, string> longURLtoTinyURL;
    unordered_map<string, string> tinyURLToLongURL;

    Solution() {
        this->ctr = 0;
    }

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {

        // longURL already exists
        if(longURLtoTinyURL.find(longUrl) != longURLtoTinyURL.end()) {
            return longURLtoTinyURL[longUrl];
        }

        // new longURL id generate
        string tinyUrl = "http://tinyurl.com/" + to_string(ctr);
        longURLtoTinyURL[longUrl] = tinyUrl;
        tinyURLToLongURL[tinyUrl] = longUrl;

        ctr++;

        return tinyUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return tinyURLToLongURL[shortUrl];
    }
};

int main() {

    return 0;
}
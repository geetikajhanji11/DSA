/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    pair<string, string> getLocalAndDomain(string email) {
        
        string local = "";
        int i = 0;
        while(email[i] != '@' && email[i] != '+') {
            if(email[i] != '.') {
                local += email[i];
            } 
            i++;
        }

        string domain = "";
        i = email.size() - 1;
        while(email[i] != '@') {
            domain = email[i] + domain;
            i--;
        }

        return {local, domain};
    }

public:
    int numUniqueEmails(vector<string>& emails) {

        unordered_map<string, unordered_set<string>> m;
        
        for(string email : emails) {
            auto p = getLocalAndDomain(email);
            string local = p.first;
            string domain = p.second;
            m[domain].insert(local);
        }

        int result = 0;
        for(auto kv : m) {
            result += kv.second.size();
        }

        return result;
    }
};
/*******************************************************************
Letter Logs
let1 art can
let2 own kit dig
let3 art zero
let4 art can

Digit Logs
dig1 8 1 5 1
dig2 3 6
dig2 3 6

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        
        unordered_map<string, set<string>> logToIds;
        vector<string> letterLogs;
        vector<string> digitLogs;

        for(string log : logs) {
            
            // get the identifier of log
            int i = 0;
            string id = "";
            while(log[i] != ' ') {
                id += log[i];
                i++;
            }
            i++;

            // letter log
            if(isalpha(log[i])) {
                int logLength = log.length() - id.length();
                string logContent = log.substr(i, logLength);

                if(logToIds.find(logContent) == logToIds.end()) {
                    letterLogs.push_back(logContent);
                } 

                logToIds[logContent].insert(id);
            }
            
            // digit log
            else {
                digitLogs.push_back(log);
            }

        }

        sort(letterLogs.begin(), letterLogs.end());
        
        vector<string> result;
        for(string logContent : letterLogs) {
            set<string> ids = logToIds[logContent];
            for(string id : ids) {
                string letterLog = id + " " + logContent;
                result.push_back(letterLog);
            }
        }

        result.insert(result.end(), digitLogs.begin(), digitLogs.end());

        return result;
    }
};
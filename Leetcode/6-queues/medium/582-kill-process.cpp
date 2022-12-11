/*******************************************************************
* @param pid: the process id
* @param ppid: the parent process id
* @param kill: a PID you want to kill
* @return: a list of PIDs of processes that will be killed in the end
*          we will sort your return value in output
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill) {
        unordered_map<int, vector<int>> children;

        for(int i=0; i<pid.size(); i++) {
            int child = pid[i];
            int parent = ppid[i];
            children[parent].push_back(child);
        }

        queue<int> targetKills;
        targetKills.push(kill);
        
        vector<int> result;

        while(!targetKills.empty()) {
            int process = targetKills.front();
            targetKills.pop();

            result.push_back(process);

            for(int child : children[process]) {
                targetKills.push(child);
            }

            children.erase(process);
        }

        return result;
    }
};
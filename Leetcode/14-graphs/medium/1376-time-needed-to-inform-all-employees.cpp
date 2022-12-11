/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    unordered_map<int, vector<int>> adjList;
    
    // mapping manager => [emp1, emp2] employee list 
    for(int employee=0; employee<n; employee++) {
        int curr_manager = manager[employee];
        adjList[curr_manager].push_back(employee);
    }        

    // first => employee id
    // second => cumulative time taken for info to reach this emp's subordinates
    queue<pair<int, int>> q; 
    int max_time = 0;

    q.push({headID, informTime[headID]});

    while(!q.empty()) {

        int curr_manager = q.front().first;
        int curr_inform_time = q.front().second;
        q.pop();

        max_time = max(max_time, curr_inform_time);

        for(int employee : adjList[curr_manager]) {
            q.push({employee, informTime[employee] + curr_inform_time});
        }
    }

    return max_time;
}

int main() {

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool can_finish_course(int course, unordered_map<int, vector<int>> &pre_map, vector<bool> &visited, vector<int> &result) {
    
    if(visited[course]) {
        if(pre_map[course].empty()) return true; // no need to add for visited course, since we already must have added to result
        else return false; // visiting a visited course again and noticing it still has prerequistes to finish, so course cannot be finished (cycle detected)
    }

    visited[course] = true;
    if(pre_map[course].empty()) { // if there are no prerequisites for unvisited course, add to result
        result.push_back(course);
        return true;
    }

    vector<int> prerequisites = pre_map[course];
    for(int prereq : prerequisites) {
        if(!can_finish_course(prereq, pre_map, visited, result)) return false;
    }

    pre_map[course].clear();
    result.push_back(course); // all prerequisites for this unvisited course can be finished, so add to result

    return true;
}   

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> pre_map;
    for(auto pre : prerequisites) {
        pre_map[pre[0]].push_back(pre[1]);
    }

    vector<bool> visited(numCourses, false);
    vector<int> result;

    for(int course=0; course<numCourses; course++) {
        if(!can_finish_course(course, pre_map, visited, result)) {
            return {};
        }
    }

    return result;
}

// **************** ALSO WORKS ****************
class Solution {
public:
    bool can_finish_course(int course, unordered_map<int, unordered_set<int>> &pre_map, vector<bool> &visited, vector<int> &result) {

        if(visited[course] && pre_map[course].size() == 0) return true;
        if(visited[course] && pre_map[course].size() != 0) return false;

        visited[course] = true;
        if(pre_map[course].size() == 0) {
            result.push_back(course);
            return true;
        }

        auto temp_pre_map = pre_map[course];
        for(int pre : temp_pre_map) {
            if(!can_finish_course(pre, pre_map, visited, result)) return false;
            pre_map[course].erase(pre);
        }

        result.push_back(course);
        return true;
    } 

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, unordered_set<int>> pre_map;
        vector<bool> visited(numCourses, false);

        for(int i=0; i<numCourses; i++) {
            unordered_set<int> v;
            pre_map[i] = v;
        }        

        for(auto prerequisite : prerequisites) {
            int a = prerequisite[0];
            int b = prerequisite[1];
            pre_map[a].insert(b);
        }

        vector<int> result;
        for(int course=0; course<numCourses; course++) {
            if(!can_finish_course(course, pre_map, visited, result)) 
                return {};
        }

        return result;

    }
};

int main() {

    return 0;
}
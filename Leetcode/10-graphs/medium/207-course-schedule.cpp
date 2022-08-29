/*******************************************************************
Courses & prerequisites, return true if can finish all courses
Ex. numCourses = 2, prerequisites = [[1,0]] -> true

All courses can be completed if there's no cycle (visit already visited)

Time: O(V + E)
Space: O(V + E)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool can_finish_course(int course, unordered_map<int, vector<int>> &pre_map, vector<bool> &visited) {

    if(visited[course]) return false;
    if(pre_map[course].empty()) return true;

    visited[course] = true;
    vector<int> prerequisites = pre_map[course];
    
    for(int prereq : prerequisites) {
        if(!can_finish_course(prereq, pre_map, visited)) return false;
    }
    
    pre_map[course].clear();
    visited[course] = false;
    return true;
}

bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    unordered_map<int, vector<int>> pre_map;
    vector<bool> visited(numCourses, false);

    for(int i=0; i<numCourses; i++) {
        vector<int> v;
        pre_map[i] = v;
    }        

    for(auto prerequisite : prerequisites) {
        int a = prerequisite[0];
        int b = prerequisite[1];
        pre_map[a].push_back(b);
    }

    for(int course=0; course<numCourses; course++) {
        if(!can_finish_course(course, pre_map, visited)) 
            return false;
    }

    return true;
}


// *************** ALSO WORKS ***************
class Solution {
public:
    bool can_finish_course(int course, unordered_map<int, unordered_set<int>> &pre_map, vector<bool> &visited) {

        if(visited[course] && pre_map[course].size() == 0) return true;
        if(visited[course] && pre_map[course].size() != 0) return false;

        visited[course] = true;
        if(pre_map[course].size() == 0) return true;

        auto temp_pre_map = pre_map[course];
        for(int pre : temp_pre_map) {
            if(!can_finish_course(pre, pre_map, visited)) return false;
            pre_map[course].erase(pre);
        }

        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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

        for(int course=0; course<numCourses; course++) {
            if(!can_finish_course(course, pre_map, visited)) 
                return false;
        }

        return true;
    }
};

int main() {

    vector<vector<int>> prerequisites = {
        {0, 1},
        {0, 2},
        {1, 3},
        {1, 4},
        {3, 4}
    };
    canFinish(5, prerequisites);
    return 0;
}
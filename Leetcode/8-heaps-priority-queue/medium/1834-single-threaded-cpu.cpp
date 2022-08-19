/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Task {
public:
    int id;
    int startTime;
    int duration;

    Task(int id, int startTime, int duration) {
        this->id = id;
        this->startTime = startTime;
        this->duration = duration;
    } 
};

static bool tasksSort(Task t1, Task t2) {
    return t1.startTime < t2.startTime;
}

class Compare {
public:
    bool operator() (Task t1, Task t2) {
        if(t1.duration == t2.duration) {
            return t1.id > t2.id;
        }
        return t1.duration > t2.duration;
    }
};

vector<int> getOrder(vector<vector<int>>& tasks) {

    int n = tasks.size();

    vector<Task> allTasks;
    for(int i=0; i<n; i++) { 
        allTasks.push_back(Task(i, tasks[i][0], tasks[i][1]));
    }

    // sorting all tasks (ascending startTime) 
    sort(allTasks.begin(), allTasks.end(), tasksSort);

    priority_queue<Task, vector<Task>, Compare> min_heap;

    long long int currTime = allTasks[0].startTime;
    int i = 0; 
    vector<int> order;

    while(!min_heap.empty() || i < n) {

        // keep adding tasks in the min heap
        // which can be processed at currTime
        while(i < n && currTime >= allTasks[i].startTime) {
            min_heap.push(allTasks[i]);
            i++;
        }

        // min heap is not empty
        // process top task
        if(!min_heap.empty()) {
            Task processingTask = min_heap.top();
            min_heap.pop();
            order.push_back(processingTask.id);
            currTime += processingTask.duration;
        } 
        
        // min heap is empty
        // cpu is idle
        // make currTime = current task's startTime 
        else {
            currTime = allTasks[i].startTime;
        }
    }

    return order;
}

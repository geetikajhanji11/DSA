/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Server {
public:
    int id;
    int weight;
    int time;
    Server(int id, int weight, int timeEnd = -1) {
        this->id = id;
        this->weight = weight;
        this->time = timeEnd;
    }
};

class CompareFree {
public:
    bool operator()(Server s1, Server s2) {
        if(s1.weight == s2.weight) {
            return s1.id > s2.id;
        }
        return s1.weight > s2.weight;
    } 
};

class CompareOccupied {
public:
    bool operator()(Server s1, Server s2) {
        return s1.time > s2.time;
    } 
};

vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

    priority_queue<Server, vector<Server>, CompareFree> freeServers;
    priority_queue<Server, vector<Server>, CompareOccupied> occupiedServers;
    
    for(int i=0; i<servers.size(); i++) {
        freeServers.push(Server(i, servers[i]));
    }

    int currTime = 0;
    vector<int> result;

    for(int i=0; i<tasks.size(); i++) {

        currTime = max(currTime, i);

        if(freeServers.empty()) {
            currTime = occupiedServers.top().time;
        }

        while(!occupiedServers.empty() && occupiedServers.top().time <= currTime) {
            Server s = occupiedServers.top();
            occupiedServers.pop();
            freeServers.push(Server(s.id, s.weight));
        }

        // assign this server the task
        Server s = freeServers.top();
        freeServers.pop();

        result.push_back(s.id);

        occupiedServers.push(Server(s.id, s.weight, currTime + tasks[i]));
    }

    return result;
} 

int main() {

    return 0;
}
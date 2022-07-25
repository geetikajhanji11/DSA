/*******************************************************************
Given array of tasks & cooldown b/w same tasks, return least # of units of time
Ex. tasks = ["A","A","A","B","B","B"] n = 2 -> 8 (A->B->idle->A->B->idle->A->B)

Key is to determine # of idles, greedy: always arrange task w/ most freq first
3A, 2B, 1C -> A??A??A -> AB?AB?A -> ABCAB#A, since A most freq, needs most idles

Time: O(n)
Space: O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> counter(26);
        
        int maxCount = 0;
        int maxCountFrequency = 0;
        
        for (int i = 0; i < tasks.size(); i++) {
            counter[tasks[i] - 'A']++;
            int currCount = counter[tasks[i] - 'A'];
            
            if (maxCount == currCount) {
                maxCountFrequency++;
            } else if (maxCount < currCount) {
                maxCount = currCount;
                maxCountFrequency = 1;
            }
        }
        
        int partCount = maxCount - 1;
        int partLength = n - (maxCountFrequency - 1);
        int emptySlots = partCount * partLength;
        int availableTasks = tasks.size() - maxCount * maxCountFrequency;
        int idles = max(0, emptySlots - availableTasks);
        
        return tasks.size() + idles;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    
    unordered_map<char, int> count;
    for(char task : tasks) count[task]++;

    priority_queue<int> max_heap;
    queue<pair<int, int>> q;

    // put all task counts in max heap
    for(auto it=count.begin(); it!=count.end(); it++) {
        max_heap.push(it->second);
    }

    // logic
    int time = 0;
    while(!max_heap.empty() || !q.empty()) {

        // increment time
        time++;

        // check max heap
        if(!max_heap.empty()) {
            int task_freq = max_heap.top();
            max_heap.pop();
            if(task_freq-1 != 0) {
                q.push({task_freq-1, time+n});
            }
        }
        
        // check in queue 
        if(!q.empty() && q.front().second == time) {
            int task_freq = q.front().first;
            q.pop();
            max_heap.push(task_freq);
        }
 
    }

    return time;
}

int main() {

    return 0;
}
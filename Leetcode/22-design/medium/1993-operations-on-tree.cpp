/*******************************************************************
["LockingTree","lock","unlock","unlock","lock","upgrade","lock"]
[[[-1,0,0,1,1,1,2,2]],[2,2],[2,3],[2,2],[4,5],[0,1],[0,1]]
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class LockingTree {

    class Node {
    public:
        int val;
        bool isLocked;
        int userId;
        vector<int> children;
        Node(int val) {
            this->val = val;
            this->isLocked = false;
            this->userId = -1;
        }
    };

    vector<int> parent;
    unordered_map<int, Node*> nodes;

public:
    LockingTree(vector<int>& parent) {
        int n = parent.size();
        this->parent = parent;

        for(int i=0; i<n; i++) {
            nodes[i] = new Node(i);
        }

        for(int child=1; child<n; child++) {
            int p = parent[child];
            nodes[p]->children.push_back(child);
        }
    }
    
    bool lock(int num, int user) {

        // node does not exist
        if(nodes.find(num) == nodes.end()) return false;

        // get target node
        Node* targetNode = nodes[num];

        // node is already locked,
        // cannot lock
        if(targetNode->isLocked) return false;

        // node is unlocked,
        // lock it
        targetNode->isLocked = true;
        targetNode->userId = user;
        
        return true;
    }
    
    bool unlock(int num, int user) {

        // node does not exist
        if(nodes.find(num) == nodes.end()) return false;
        
        // get target node
        Node* targetNode = nodes[num];

        // node is already unlocked,
        // cannot unlock an unlocked node
        if(!targetNode->isLocked) return false;

        // unauthorised user is trying
        // to unlock the node
        if(targetNode->userId != user) return false;
        
        // correct user is unlocking
        targetNode->isLocked = false;
        targetNode->userId = -1;

        return true;
    }
    
    bool upgrade(int num, int user) {

        // node does not exist
        if(nodes.find(num) == nodes.end()) return false;

        // get target node
        Node* targetNode = nodes[num];

        // check if all ancestors are unlocked
        int child = num;
        while(child != -1) {
            if(nodes[child]->isLocked) return false;
            child = parent[child];
        }

        // check is at least one descendent is locked
        queue<int> q;
        q.push(num);

        vector<Node*> lockedDescendents;

        while(!q.empty()) {
            int currNum = q.front();
            q.pop();
            if(nodes[currNum]->isLocked) {
                lockedDescendents.push_back(nodes[currNum]);
            }
            for(int currChild : nodes[currNum]->children) {
                q.push(currChild);
            }
        }

        // no decendent is locked
        if(lockedDescendents.size() == 0) return false;

        // unlock all descendents
        for(Node* descendent : lockedDescendents) {
            descendent->isLocked = false;
            descendent->userId = -1;
        }

        // all conditions are met,
        // lock the current node 
        targetNode->isLocked = true;
        targetNode->userId = user;

        return true;
    }
};

/**
 * Your LockingTree object will be instantiated and called as such:
 * LockingTree* obj = new LockingTree(parent);
 * bool param_1 = obj->lock(num,user);
 * bool param_2 = obj->unlock(num,user);
 * bool param_3 = obj->upgrade(num,user);
 */
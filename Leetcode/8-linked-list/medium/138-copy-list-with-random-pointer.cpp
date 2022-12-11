#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

Node* copyRandomList(Node* head) {
    
    Node* temp = head;
    Node* new_head = NULL;
    Node* curr = NULL;

    // make a new node for every node
    // encountered in the original ll
    // and make a copy of exactly
    // like a normal linked list.
    // make random pointers point to orignal node
    // and insert og_node_pointer => new_node_pointer
    unordered_map<Node*, Node*> m;
    while(temp != NULL) {
        Node* new_node = new Node(temp->val);
        if(new_head == NULL) {
            new_head = new_node;
            curr = new_node;
        } else {
            curr->next = new_node;
            curr = curr->next;
        }
        new_node->random = temp;
        m[temp] = new_node;

        temp = temp->next;
    }

    // hanging random pointers
    curr = new_head;
    while(curr != NULL) {

        Node* target = curr->random->random;
        if(target == NULL) {
            curr->random = NULL;
        } else {
            curr->random = m[target];
        }
        curr = curr->next;
    }
    return new_head;
}

int main() {

    return 0;
}
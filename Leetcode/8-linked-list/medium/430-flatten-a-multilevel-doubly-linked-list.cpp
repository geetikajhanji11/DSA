/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


Node* flatten(Node* head) {

    if(head == NULL) return NULL;
    
    stack<Node*> s;

    Node* temp = head;
    Node* lastNode = NULL;

    while(!s.empty() || lastNode == NULL) {

        if(lastNode != NULL && s.empty()) break;

        if(lastNode != NULL) {
            Node* topNode = s.top();
            s.pop();
            lastNode->next = topNode;
            topNode->prev = lastNode;
            temp = topNode;
        }

        while(temp != NULL) {

            // there is a child
            if(temp->child != NULL) {

                if(temp->next != NULL) {
                    s.push(temp->next); // have to handle prev of stack Nodes
                }

                Node* child = temp->child;
                child->prev = temp;

                temp->child = NULL;
                temp->next = child;

            } 

            lastNode = temp;
            temp = temp->next;

        }
    }

    return head;
}


int main() {

    return 0;
}
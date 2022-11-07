/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

class MyCircularQueue {
    int capacity;
    int size;
    Node* head;
    Node* tail;

public:
    MyCircularQueue(int k) {
        this->capacity = k;
        this->size = 0;
        this->head = NULL;
        this->tail = NULL;
    }
    
    bool enQueue(int value) {
        if(size == capacity) return false;
        
        Node* newNode = new Node(value);
        if(size == 0) {
            head = newNode;
            tail = newNode;
            
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        tail->next = head;
        size++;

        return true;
    }
    
    bool deQueue() {
        if(size == 0) return false;

        Node* newHead = head->next;
        delete head;
        size--;

        // there was only 1 element in LL
        if(size == 0) {
            head = NULL;
            tail = NULL;

        } else {
            head = newHead;
            tail->next = head;
        }
        
        return true;
    }
    
    int Front() {
        if(size == 0) return -1;
        return head->val;
    }
    
    int Rear() {
        if(size == 0) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
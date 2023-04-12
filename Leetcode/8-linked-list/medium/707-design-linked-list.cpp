/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class MyLinkedList {
private:
    int totalNodes;
    Node* head;
    Node* tail;

public:
    MyLinkedList() {
        totalNodes = 0;
        head = NULL;
        tail = NULL;
    }

    int get(int index) {
        if (index < 0 || index >= totalNodes) {
            return -1;
        }

        Node* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);

        if (totalNodes == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        totalNodes++;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (totalNodes == 0) {
            head = newNode;
            tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        totalNodes++;
    }

    void addAtIndex(int index, int val) {
        if (index > totalNodes) {
            return;
        }
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == totalNodes) {
            addAtTail(val);
            return;
        }

        Node* newNode = new Node(val);
        Node* temp = head;

        for (int i = 0; i < index - 1; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
        totalNodes++;
    }

    void deleteAtIndex(int index) {
        if (index < 0 || index >= totalNodes) {
            return;
        }
        if (totalNodes == 1) {
            delete head;
            head = NULL;
            tail = NULL;
            totalNodes = 0;
            return;
        }
        if (index == 0) {
            Node* temp = head;
            head = head->next;
            head->prev = NULL;
            delete temp;
            totalNodes--;
            return;
        }
        if (index == totalNodes - 1) {
            Node* temp = tail;
            tail = tail->prev;
            tail->next = NULL;
            delete temp;
            totalNodes--;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        delete temp;
        totalNodes--;
    }
};

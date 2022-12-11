#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// ITERATIVE
ListNode* reverseList(ListNode* head) {

    ListNode *prev = NULL;
    ListNode *curr = head;
    
    while(curr != NULL) {
        
        ListNode *nxt = curr->next;
        
        curr->next = prev;

        prev = curr;
        curr = nxt;
    }

    return prev;
}

// RECURSIVE
ListNode* reverseList(ListNode* head) {

    if(head == NULL || head->next == NULL) return head;

    ListNode* rest = reverseList(head->next);
    ListNode* lastNodeOfRest = head->next;
    lastNodeOfRest->next = head;
    head->next = NULL;

    return rest;
}


int main() {

    return 0;
}
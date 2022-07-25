/*******************************************************************

*******************************************************************/

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

ListNode* deleteDuplicates(ListNode* head) {
    
    if(head == NULL) return NULL;

    ListNode* curr = head;

    while(curr != NULL) {
        ListNode* nxt = curr->next;
        while(nxt != NULL && curr->val == nxt->val) {
            nxt = nxt->next;
        }
        curr->next = nxt;
        curr = nxt; 
    }

    return head;
}

int main() {

    return 0;
}
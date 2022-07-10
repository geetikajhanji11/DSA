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


ListNode* getMiddle(ListNode* head) {
    if(head == NULL) return head;
    ListNode* slow = head;
    ListNode* fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* reverseList(ListNode* head) {
    if(head == NULL || head->next == NULL) return head;
    
    ListNode* rest = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;

    return rest;
}

void reorderList(ListNode* head) {
    
    if(head == NULL || head->next == NULL) return;
    
    ListNode* mid = getMiddle(head);
    ListNode* list1 = head;
    ListNode* list2 = mid->next;
    mid->next = NULL;

    list2 = reverseList(list2);

    ListNode* curr = head;
    ListNode* nxt = list2;
    ListNode* next_l1 = list1->next;
    ListNode* next_l2 = list2->next;
    while(curr != NULL) {

        ListNode* future_next = curr->next;
        curr->next = nxt;
        curr = nxt;
        nxt = future_next;

    }
    
}

int main() {

    return 0;
}
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

bool isPalindrome(ListNode* head) {

    ListNode* slow = head;
    ListNode* fast = head;

    ListNode* prev = slow;
    while(fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }        

    // slow is not at the middle of the linked list
    // reverse this linked list
    ListNode* p1 = head;
    prev->next = NULL;
    ListNode* p2 = reverseList(slow);

    while(p2 != NULL && p1 != NULL) {
        if(p1->val != p2->val) return false;
        p1 = p1->next;
        p2 = p2->next;
    }

    return false;
}   


int main() {

    return 0;
}
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


ListNode* swapPairs(ListNode* head) {

    if(head == NULL || head->next == NULL) return head; 

    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* before = dummy;
    ListNode* first = before->next;

    while(first != NULL && first->next != NULL) {
        ListNode* second = first->next;
        ListNode* after = second->next;

        before->next = second;
        second->next = first;
        first->next = after;

        before = first;
        first = after;
    }

    return dummy->next;
}



class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* first = head;
        ListNode* second = head->next;

        while(first != NULL && second != NULL) {
            ListNode* nextFirst = second->next;

            prev->next = second;
            first->next = second->next;
            second->next = first;

            prev = first;
            first = nextFirst;
            if(nextFirst != NULL) second = nextFirst->next;
            
        }   

        return dummy->next;
    }
};

int main() {

    return 0;
}
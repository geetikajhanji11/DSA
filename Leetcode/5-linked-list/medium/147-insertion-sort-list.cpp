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

class Solution {

    void insert(ListNode* &sortedHead, ListNode* &sortedTail, ListNode* &target) {
        ListNode* prev = NULL;
        ListNode* curr = sortedHead;

        while(curr->val < target->val) {
            prev = curr;
            curr = curr->next;
        }

        if(prev == NULL) {
            sortedTail->next = target->next;
            target->next = sortedHead;
            sortedHead = target;
            return;
        } 
        
        prev->next = target;
        target->next = curr;
    }

public:
    ListNode* insertionSortList(ListNode* head) {
        
        if(head == NULL || head->next == NULL) return head;
         
        ListNode* sortedHead = head;
        ListNode* sortedTail = head;

        ListNode* curr = head->next;
        while(curr != NULL) {
            
            ListNode* nextNode = curr->next;

            if(curr->val >= sortedTail->val) {
                sortedTail = curr;
            } else {
                insert(sortedHead, sortedTail, curr);
                sortedTail->next = nextNode;
            }

            curr = nextNode;
        }

        return sortedHead;
    }
};
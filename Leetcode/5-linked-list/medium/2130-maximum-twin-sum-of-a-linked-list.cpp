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
public:
    int pairSum(ListNode* head) {
        
        // find middle node
        ListNode* slow = head;
        ListNode* fast = head->next; // for even, have to do this
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // slow is at mid
        ListNode* l1 = head;
        ListNode* l2 = slow->next; 
        slow->next = NULL;
        l2 = reverseList(l2);

        // simultaneous traversal
        int maxSum = INT_MIN;
        while(l1 != NULL) {
            maxSum = max(maxSum, l1->val + l2->val);
            l1 = l1->next;
            l2 = l2->next;
        }

        return maxSum;    
    }
};
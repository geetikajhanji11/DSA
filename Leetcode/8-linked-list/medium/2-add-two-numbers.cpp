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

// *************** ALTERNATE SOLUTION ***************
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* h1 = l1;
        ListNode* h2 = l2;

        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int carry = 0;

        while(h1 != NULL || h2 != NULL) {

            int sum = 0;

            if(h1 && h2) {
                sum = h1->val + h2->val + carry;
                h1 = h1->next;
                h2 = h2->next;
            }

            else if(h1) {
                sum = h1->val + carry;
                h1 = h1->next;
            }

            else if(h2) {
                sum = h2->val + carry;
                h2 = h2->next;
            }

            int quo = sum / 10;
            int rem = sum % 10;
            curr->next = new ListNode(rem);
            carry = quo;
            curr = curr->next;
        }

        if(carry > 0) {
            curr->next = new ListNode(carry);
        }

        return head->next;
    }
};

// *************** ALTERNATE SOLUTION ***************
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;

    int carry = 0;
    while(l1 != NULL && l2 != NULL) {
        int sum = l1->val + l2->val + carry;
        carry = sum / 10;
        if(carry == 1) sum = sum - 10;
        curr->next = new ListNode(sum);
        curr = curr->next;
        
        l1 = l1->next;
        l2 = l2->next;
    }

    while(l1 != NULL) {
        int sum = carry + l1->val;
        carry = sum / 10;
        if(carry == 1) sum = sum - 10;
        curr->next = new ListNode(sum);
        curr = curr->next;

        l1 = l1->next;
    }

    while (l2 != NULL) {
        int sum = carry + l2->val;
        carry = sum / 10;
        if(carry == 1) sum = sum - 10;
        curr->next = new ListNode(sum);
        curr = curr->next;

        l2 = l2->next;
    }
    

    if(carry == 1) {
        curr->next = new ListNode(carry);
        curr = curr->next;
    }

    curr->next = NULL;
    return dummy->next;
}

int main() {

    return 0;
}
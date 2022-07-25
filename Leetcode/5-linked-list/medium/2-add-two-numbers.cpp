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
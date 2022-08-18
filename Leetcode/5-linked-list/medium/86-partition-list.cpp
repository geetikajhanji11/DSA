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

ListNode* partition(ListNode* head, int x) {

    ListNode* leftHead = new ListNode(); // dummy head
    ListNode* left = leftHead;

    ListNode* rightHead = new ListNode(); // dummy head
    ListNode* right = rightHead;

    ListNode* temp = head;
    while(temp != NULL) {
        if(temp->val < x) {
            left->next = temp;
            left = left->next; 
        } else {
            right->next = temp;
            right = right->next;
        }
        temp = temp->next;
    }

    left->next = rightHead->next;
    right->next = NULL;

    return leftHead->next;
}

int main() {

    return 0;
}

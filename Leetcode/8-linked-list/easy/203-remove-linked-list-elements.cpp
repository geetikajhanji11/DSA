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

ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;

    ListNode* curr = dummy;
    while(curr != NULL) {
        
        ListNode* temp = curr->next;
        ListNode* prev = temp;
        if(temp != NULL && temp->val == val) {
            while(temp != NULL && temp->val == val) {
                prev = temp;
                temp = temp->next;
            }
            curr->next = temp;
            delete prev;
            curr = temp;
        } else {
            curr = curr->next;
        }
    } 

    return dummy->next;
}

int main() {

    return 0;
}
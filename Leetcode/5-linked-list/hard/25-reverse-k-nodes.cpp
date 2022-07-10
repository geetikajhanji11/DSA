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

ListNode* getKth(ListNode* curr, int k) {
    while(curr != NULL && k > 0) {
        curr = curr->next;
        k--;
    }
    return curr;
}

ListNode* reverseKGroup(ListNode* head, int k) {

    ListNode* dummy = new ListNode(0, head);
    ListNode* groupPrev = dummy;

    while(true) {
        ListNode* kth = getKth(groupPrev, k);
        if(kth == NULL) break;

        ListNode* groupNext = kth->next;

        // reversing group
        ListNode* prev = kth->next;
        ListNode* curr = groupPrev->next;
        while(curr != groupNext) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // new group's groupPrev will be the 
        // last node of the current group's
        // reversed version
        ListNode* temp = groupPrev->next; // temp = the last node of the current group's reversed version
        groupPrev->next = kth; // making the first node of the current group's reversed version as the start
        groupPrev = temp;
    }

    return dummy->next;

}

int main() {

    return 0;
}
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

// ********** USING DUMMY **********
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* curr = dummy;
        ListNode* fast = head;

        while(n > 0) {
            fast = fast->next;
            n--;
        }

        ListNode* prev = dummy;

        while(fast != NULL) {
            prev = prev->next;
            fast = fast->next;
        }

        ListNode* target = prev->next;
        prev->next = target->next;
        delete target;

        return dummy->next;
    }
};

// ********** ALTERNATE **********
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* slow = head;
    ListNode* fast = head;

    while(n != 0) {
        fast = fast->next;
        n--;
    }

    // edge case: if n == length of the linked list
    // then remove the first node from list
    if(fast == NULL) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
        return head;
    }

    while(fast->next != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    // slow is 1 pos behind nth node
    ListNode* nth = slow->next;
    slow->next = nth->next;
    delete nth;

    return head;
}

int main() {

    return 0;
}
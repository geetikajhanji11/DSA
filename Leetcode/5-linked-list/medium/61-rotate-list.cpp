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

ListNode* rotateRight(ListNode* head, int k) {
    
    if(head == NULL) return NULL;

    int size = 0;
    ListNode* temp = head;
    ListNode* tail = NULL;
    while(temp != NULL) {
        tail = temp;
        temp = temp->next;
        size++;
    }

    k = k % size;
    if(k == 0) return head;
    k = size - k - 1;

    // Skip first size-k-1 elements
    temp = head;
    while(k != 0) {
        temp = temp->next;
        k--;
    }
    ListNode* newHead = temp->next;
    temp->next = NULL;
    tail->next = head;

    return newHead;

}

int main() {
    return 0;
}
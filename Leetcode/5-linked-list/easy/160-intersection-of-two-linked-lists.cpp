/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    
    // get lengths of both ll
    int lenA = 0;
    ListNode* temp = headA;
    while(temp != NULL) {
        lenA++;
        temp = temp->next;
    }

    int lenB = 0;
    temp = headB;
    while(temp != NULL) {
        lenB++;
        temp = temp->next;
    }

    // traverse until both have equal length
    while(lenA > lenB) {
        headA = headA->next;
        lenA--;
    }
    while(lenB > lenA) {
        headB = headB->next;
        lenB--;
    }

    // iterate both together
    while(headA != NULL && headB != NULL) {
        if(headA == headB) return headA;
        headA = headA->next;
        headB = headB->next;
    }

    return NULL;
}
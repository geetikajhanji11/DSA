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

int getDecimalValue(ListNode* head) {

    if(head == NULL) return 0;

    int n = -1;
    ListNode* temp = head;
    while(temp != NULL) {
        temp = temp->next;
        n++;
    }
    
    temp = head;
    int number = 0;
    while(temp != NULL) {
        int bit = temp->val;
        temp = temp->next;

        number += bit * pow(2, n);
        n--;
    }

    return number;
}



int main() {

    return 0;
}
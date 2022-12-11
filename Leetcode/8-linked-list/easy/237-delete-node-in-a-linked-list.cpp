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
public:
    void deleteNode(ListNode* node) {
        
        ListNode* prevNode = node;
        ListNode* curr = node->next;

        while(curr->next != NULL) {
            prevNode->val = curr->val;
            prevNode = curr;
            curr = prevNode->next;
        }

        prevNode->val = curr->val;
        prevNode->next = NULL;
        delete curr;
    }
};


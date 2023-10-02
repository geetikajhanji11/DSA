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

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    ListNode* dummy = new ListNode(0);
    ListNode* temp = dummy;

    while(list1 != NULL && list2 != NULL) {
        cout<<temp->val<<endl;
        if(list1->val <= list2->val) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        temp = temp->next;
    }

    while(list1 != NULL) {
        temp->next = list1;
        temp = temp->next;
        list1 = list1->next; 
    }

    while(list2 != NULL) {
        temp->next = list2;
        temp = temp->next;
        list2 = list2->next;
    }

    return dummy->next;

}

// ***************** ONE LOOP ***************** 
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* h1 = list1;
        ListNode* h2 = list2;
        ListNode* head = new ListNode(0);
        ListNode* result_head = head; 

        while(h1 != NULL || h2 != NULL) {

            if(h1 != NULL && h2 != NULL) {
                if(h1->val <= h2->val) {
                    head->next = new ListNode(h1->val);
                    h1 = h1->next;
                } else {
                    head->next = new ListNode(h2->val);
                    h2 = h2->next;
                }
                head = head->next;
            }

            else if(h1 != NULL) {
                head->next = new ListNode(h1->val);
                h1 = h1->next;
                head = head->next;
            }

            else if(h2 != NULL) {
                head->next = new ListNode(h2->val);
                h2 = h2->next;
                head = head->next;
            }
        }



        return result_head->next;
    }
};
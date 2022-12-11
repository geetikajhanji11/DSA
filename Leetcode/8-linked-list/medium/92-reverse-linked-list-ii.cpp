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

ListNode* reverseList(ListNode* head) {

    if(head == NULL || head->next == NULL) return head;

    ListNode* rest = reverseList(head->next);
    ListNode* lastNodeOfRest = head->next;
    lastNodeOfRest->next = head;
    head->next = NULL;

    return rest;
}

ListNode* reverseBetween(ListNode* head, int left, int right) {
    
    if(left == right) return head;
    
    left--;
    right = right - left - 1;
    
    ListNode* dummy = new ListNode();
    dummy->next = head;

    ListNode* prev = dummy;
    ListNode* left_node = head;
    while(left_node != NULL && left > 0) {
        prev = left_node;
        left_node = left_node->next;
        left--;
    }

    ListNode* right_node = left_node;
    ListNode* nxt = right_node == NULL ? NULL : right_node->next;
    while(right_node != NULL && right > 0) {
        right_node = right_node->next;
        nxt = right_node == NULL ? NULL : right_node->next;
        right--;
    }


    //  cout<<"left = "<<left_node->val<<", right = "<<right_node->val<<endl;
    // string out1 = prev != NULL ? to_string(prev->val) : "NULL";
    // string out2 = nxt != NULL ? to_string(nxt->val) : "NULL";
    //  cout<<"prev = "<<out1<<", nxt = "<<out2;


    if(right_node != NULL) right_node->next = NULL;
    ListNode* new_head = reverseList(left_node);

    prev->next = new_head;
    ListNode* temp = new_head;
    while(temp != NULL && temp->next != NULL) {
        temp = temp->next;
    }
    if(temp != NULL) temp->next = nxt;

    return dummy->next;

}

int main() {

    return 0;
}
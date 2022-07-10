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

ListNode* merge(ListNode* list1, ListNode* list2) {
    
    //base case
	if(list1 == NULL) return list2;
	if(list2 == NULL) return list1;

	//rec case
	ListNode *head;

	if(list1->val < list2->val) {
		head = list1;
		head->next = merge(list1->next, list2);
	}
	else {
		head = list2;
		head->next = merge(list1, list2->next);
	}
	return head;

}

ListNode* middleNode(ListNode* head) {
    ListNode *slow = head;
	ListNode *fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

ListNode* sortList(ListNode* head) {

    // base case    
    if(head == NULL || head->next == NULL) {
        return head;
    }

    // break at the middle
    ListNode* mid = middleNode(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL;

    // recursive sort
    left = sortList(left);
    right = sortList(right);

    // merge them
    return merge(left, right);

}

int main() {

    return 0;
}
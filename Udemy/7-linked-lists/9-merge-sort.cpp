/**************************************************************

MERGE SORT ON LINKED LIST

https://www.youtube.com/watch?v=TGveA1oFhrc&ab_channel=NeetCode

**************************************************************/
#include<iostream>
using namespace std;

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

//----------Linked List-----------//
void insertAtHead(node * &head, int data) {
	if(head == NULL){
		head = new node(data);
		return;
	}	 
	node * n = new node(data);
	n->next = head;
	head = n;
}

node* merge(node *head1, node* head2){

	//base case
	if(head1 == NULL) return head2;
	if(head2 == NULL) return head1;

	//rec case
	node *head;

	if(head1->data < head2->data) {
		head = head1;
		head->next = merge(head1->next, head2);
	}
	else {
		head = head2;
		head->next = merge(head1, head2->next);
	}
	return head;
}

node* midPoint(node *head){

	node *slow = head;
	node *fast = head->next;

	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}


// MergeSort
node* mergeSort(node *head){

	// base case
	if(head == NULL || head->next == NULL){
		return head;
	}

	// rec case
	node *mid = midPoint(head);

	// Break at the mid
	node *head1 = head;
	node *head2 = mid->next;
	mid->next = NULL;

	// Recursive Sort
	head1 = mergeSort(head1);
	head2 = mergeSort(head2);

	// Merge
	return merge(head1, head2);

}


void printList(node * head){
    cout <<endl;
	while(head!=NULL){
		cout <<head->data <<" ";
		head = head->next;
	}
}


int main() {

	node* head = NULL;
	insertAtHead(head, 10);
	insertAtHead(head, 7);
	insertAtHead(head, 5);
	insertAtHead(head, 1);
	insertAtHead(head, 17);
	insertAtHead(head, 2);
	insertAtHead(head, 14);
	printList(head);

	head = mergeSort(head);
	printList(head);


	return 0;
}
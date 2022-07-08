/**************************************************************

MERGE TWO SORTED LINKED LIST
ITERATIVE & RECURSIVE

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

// node
class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

// printing the linked list
void printList(node *head) {
    cout<<endl;
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
    
}

// insert at head
void insertAtHead(node * &head, int data){
    node *new_node = new node(data);
    if(head == NULL) {
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

// ****************** IERATIVE ******************
node* mergeIterative(node *head1, node *head2) {
    
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;

    node *h1 = NULL;
    node *h2 = NULL;

    // check first element of which list
    // is the smallest
    // h1 always has smallest 1st element
    if(head1->data < head2->data) {
        h1 = head1;
        h2 = head2;
    } else {
        h1 = head2;
        h2 = head1;
    }

    node *t1 = h1;
    node *t2 = h2;

    // merge them
    // t1 is always the smallest
    while(t1 != NULL && t2 != NULL) {

        node *next_t1 = t1->next;
        if(next_t1 == NULL) {
            break;
        }
        
        if(next_t1->data < t2->data) {
            t1 = next_t1;

        } else {
            t1->next = t2;
            t1 = next_t1;

        }

        // make t1 so it is smallest always
        if(t1->data > t2->data) {
            node *temp = t1;
            t1 = t2;
            t2 = temp; 
        }
    }

    // fill rest of t2
    while(t2 != NULL) {
        t1->next = t2;
        t2 = t2->next;
    }

    return h1;
}


// ****************** RECURSIVE ******************
node* mergeRecursive(node *head1, node *head2) {
    
    // base cases
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head2;
    
    // recursive case
    node *c;
    if(head1->data < head2->data) {
        c = head1;
        c->next = mergeRecursive(head1->next, head2);
    } else {
        c = head2;
        c->next = mergeRecursive(head1, head2->next);
    }
    return c;
}


// main function 
int main() {

    node *head1 = NULL;
    insertAtHead(head1, 10);
    insertAtHead(head1, 7);
    insertAtHead(head1, 5);
    insertAtHead(head1, 1);
    cout<<"\nLinked List 1: ";
    printList(head1);

    node *head2 = NULL;
    insertAtHead(head2, 11);
    insertAtHead(head2, 9);
    insertAtHead(head2, 8);
    insertAtHead(head2, 6);
    insertAtHead(head2, 3);
    insertAtHead(head2, 2);
    cout<<"\nLinked List 2: ";
    printList(head2);

    node *head = mergeRecursive(head1, head2);
    cout<<"\nMerged Linked List: ";
    printList(head);

    return 0;
    
}
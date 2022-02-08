/**************************************************************

K-REVERSE LINKED LIST


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

// reverse linked list iterative
node* K_reverseList(node* head, int k) {

    // one element
    if(head == NULL) {
        return head;
    }

    node *prev = NULL;
    node *curr = head;
    node *nxt;
    int count = 1;

    while(curr != NULL && count <= k) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
        count++;
    }
    
    if(nxt != NULL) {
        head->next = K_reverseList(nxt, k);
    }

    return prev;

}



// main function 
int main() {

    node *head = NULL;
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    head = K_reverseList(head, 3);

    printList(head);

    return 0;
    
}
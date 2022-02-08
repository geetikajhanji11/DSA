/**************************************************************

LINKED LIST

Creating Linked List

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

class node{
public:
	int data;
	node* next;

	node(int data){
		this->data = data;
		next = NULL;
	}
};

void printList(node *head) {
    while(head != NULL) {
        cout<<head->data<<" ";
        head = head->next;
    }
}

void insertAtHead(node * &head, int data){
    
    node *new_node = new node(data);
    if(head == NULL) {
        head = new_node;
        return;
    }
    new_node->next = head;
    head = new_node;
}

void insertInMiddle(node* &head, int data, int pos) {
    node *new_node = new node(data);

    if(head == NULL) {
        head = new_node;
        return;
    }

    if(pos == 1) {
        new_node->next = head;
        head = new_node;
        return;
    }

    node *curr = head;
    while(pos != 2) {
        if(curr == NULL) return;
        curr = curr->next;
        pos--;
    }

    if(curr == NULL) return;

    node *next_node = curr->next;
    curr->next = new_node;
    new_node->next = next_node;

}

// main function 
int main() {

    node *head = NULL;
    insertAtHead(head, 1);
    insertAtHead(head, 2);
    insertAtHead(head, 3);
    insertAtHead(head, 4);
    insertAtHead(head, 5);

    insertInMiddle(head, 99, 3);

    printList(head);

    return 0;
    
}
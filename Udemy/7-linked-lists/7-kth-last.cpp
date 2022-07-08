/**************************************************************

KTH LAST ELEMENT OF LINKED LIST

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
    cout<<endl;
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

int kthLast(node *head, int k) {
    
    node *slow = head;
    node *fast = head;
    
    while(k != 0) {
        fast = fast->next;
        k--;
    }

    while(fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow->data;
    
}



// main function 
int main() {

    node *head = NULL;
    // insertAtHead(head, 8);
    insertAtHead(head, 7);
    insertAtHead(head, 6);
    insertAtHead(head, 5);
    insertAtHead(head, 4);
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);
    printList(head);


    int mid = kthLast(head, 3);
    cout<<"\nkth Last: "<<mid;

    return 0;
    
}
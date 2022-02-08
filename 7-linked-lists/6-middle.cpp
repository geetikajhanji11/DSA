/**************************************************************

MIDDLE ELEMENT OF LINKED LIST

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

int getMid(node *head){
    //Complete this function to return data middle node

    if(head == NULL) return -1;
    if(head->next == NULL) return head->data; 
    
    node *slow = head;
    node *fast = head->next->next;
    
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    if(fast == NULL) return slow->data;

    return slow->next->data;
    
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


    int mid = getMid(head);
    cout<<"\nMiddle: "<<mid;

    return 0;
    
}
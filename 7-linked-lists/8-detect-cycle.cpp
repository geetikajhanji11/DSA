/**************************************************************

DETECT CYCLE

https://www.youtube.com/watch?v=pfA0VuvwpVg&t=280s&ab_channel=XavierElon

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

// check if it contains cycle
// also display start of cycle
bool containsCycle(node *head) {
    
    node *slow = head;
    node *fast = head;
    bool cycleFound = false;

    // detects if cycle exists
    while(fast != NULL && fast->next != NULL) {
    
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast) {
            cycleFound = true;
            break;
        }
    }

    // find starting point of cycle
    if(cycleFound) {
        node *temp = head;
        while(temp != slow) {
            temp = temp->next;
            slow = slow->next;
        }
        cout<<"\nStart at: "<<temp->data;
    }
    
    return cycleFound;

}



// main function 
int main() {

    node *head = NULL;
    node *n1 = new node(1);
    node *n2 = new node(2);
    node *n3 = new node(3);
    node *n4 = new node(4);
    node *n5 = new node(5);
    node *n6 = new node(6);
    node *n7 = new node(7);
    node *n8 = new node(8);

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n3;

    if(containsCycle(head)) {
        cout<<"\nContains Cycle";
    } else {
        cout<<"\nDoes not contain cycle";
    }

    return 0;
    
}
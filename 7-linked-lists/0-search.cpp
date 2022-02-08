/**************************************************************

LINKED LIST

Check if key is present in linked list

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

bool isPresent(node * head, int key){
    
    while(head != NULL) {
        if(head->data == key) return true;
        head = head->next;
    }
    
    return false;
    
}

// main function 
int main() {

    node *head = new node(10);
    node *curr = head;
    for(int i=0; i<10; i++) {
        node *next_node = new node(i);
        curr->next = next_node;
        curr = next_node;
    }

    cout<<isPresent(head, 111);

    return 0;
    
}
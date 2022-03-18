/******************************************************************************

BREAK THE CHAIN

Given a linked list which contains a cycle, build a hashing based algorithm
to break the cycle and return the head of the linked list, the last node
should point to null after breaking the cycle.

Input: 
    1 -> 2 -> 3 
         |    |
         5 <- 4  
Output: 
    1 -> 2 -> 3 -> 4 -> 5 -> NULL
    
*******************************************************************************/

#include<iostream>
#include<unordered_set>
using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head){
     
     unordered_set<node*> nodeSet; 
     
     node *temp = head;
     node *prevTemp = NULL;
     
     while(temp != NULL) {
         
         // cycle detected
         if(nodeSet.find(temp) != nodeSet.end()) {
             break;
         } 
         
         // insert in set
         nodeSet.insert(temp);
         prevTemp = temp;
         temp = temp->next;
     }
     
     // no cycle exists, retrun original head
     if(prevTemp == NULL) return head;
     
     // cycle exists, change pointer
     prevTemp->next = NULL;
     return head;
     
 }



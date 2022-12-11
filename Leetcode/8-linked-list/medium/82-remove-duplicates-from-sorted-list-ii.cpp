/*******************************************************************
  ListNode *dummy=new ListNode(0,head);
       ListNode *prev=dummy;
        
        while(head!=NULL){
       
        if(head->next!=NULL && head->val==head->next->val){
                
while(head->next!=NULL && head->val==head->next->val)head=head->next;
                     
                   
                        prev->next=head->next;
                }
                
                else prev=prev->next;
                       
               
                head=head->next;
        }
        
        return dummy->next;
            
    }
*******************************************************************/

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

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* prev = dummy;

        while(head != NULL) {
            
            if(head->next != NULL && head->val == head->next->val) {
                while(head->next != NULL && head->val == head->next->val) {
                    head = head->next;
                }
                prev->next = head->next;
            } 

            else {
                prev = prev->next;
            }

            head = head->next;
        }

        return dummy->next;
    }
};

// **********************
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode* temp = head;

        ListNode* newHead = new ListNode(INT_MIN);
        ListNode* curr = newHead;

        while(temp != NULL) {

            int currNum = temp->val;
            ListNode* nxt = temp->next;

            bool isADuplicate = false;
            while(nxt != NULL && nxt->val == currNum) {
                nxt = nxt->next;
                isADuplicate = true;
            }

            if(!isADuplicate) {
                curr->next = new ListNode(currNum);
                curr = curr->next;
            }

            temp = nxt;
            
        }

        return newHead->next;
    }
};
/*******************************************************************

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
    ListNode* oddEvenList(ListNode* head) {
        
        // for [], [1]
        if(head == NULL || head->next == NULL) {
            return head;
        }
            
        // for lists >= 2 nodes
        ListNode* prevOdd = head;
        ListNode* currEven = prevOdd->next;
        ListNode* odd = head->next->next;

        while(odd != NULL) {
            
            ListNode* nextEven = odd->next;
            ListNode* evenBegin = prevOdd->next;

            prevOdd->next = odd;
            
            odd->next = evenBegin;
            currEven->next = nextEven;

            prevOdd = odd;
            if(nextEven == NULL) break;
            odd = nextEven->next;
            currEven = currEven->next;
        }

        return head;
    }
};
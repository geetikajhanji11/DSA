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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// *************** O(1) SOLUTION ***************
class Solution {

    ListNode* getBeforeMiddle(ListNode* &head) {

        ListNode* beforeSlow = NULL;
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != NULL && fast->next != NULL) {
            beforeSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        return beforeSlow;
    }

    TreeNode* build(ListNode* head) {

        if(head == NULL) return NULL;

        if(head->next == NULL) return new TreeNode(head->val);

        ListNode* beforeMid = getBeforeMiddle(head);
        ListNode* mid = beforeMid->next;

        beforeMid->next = NULL;

        TreeNode* root = new TreeNode(mid->val);
        root->left = build(head);
        root->right = build(mid->next);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        return build(head);
    }
};

// *************** ARRAY SOLUTION ***************
class Solution {

    vector<int> listToVector(ListNode* head) {
        vector<int> nums;
        while(head != NULL) {
            nums.push_back(head->val);
            head = head->next;
        }
        return nums;
    }

    TreeNode* build(int left, int right, vector<int> &nums) {
        if(left > right) return NULL;

        int idx = (left + right) / 2;
        int val = nums[idx];

        TreeNode* root = new TreeNode(val);
        root->left = build(left, idx-1, nums);
        root->right = build(idx+1, right, nums);

        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums = listToVector(head);
        return build(0, nums.size()-1, nums);
    }
};
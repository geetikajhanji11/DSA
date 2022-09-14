/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node *left, *right;
};

node* newNode(int data) {
    node* temp = new node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return (temp);
}

// ************** GFG SOLUTION **************
bool inRange(node* root, int &low, int &high, int &count) {
    if(root == NULL) return true;

    bool leftInRange = inRange(root->left, low, high, count);
    bool rightInRange = inRange(root->right, low, high, count);

    if(leftInRange && rightInRange && (low <= root->data && root->data <= high)) {
        count++;
        return true;
    }

    return false;
}

int getCount(node* root, int low, int high) {
   
}

// ************** MY SOLUTION **************
pair<int, int> getRange(node* root, int &low, int &high, int &count) {
    if(root == NULL) return {INT_MIN, INT_MAX};
    
    auto left = getRange(root->left, low, high, count);
    auto right = getRange(root->right, low, high, count);

    pair<int, int> range = {left.first, right.second};
    if(root->left == NULL) range.first = root->data;
    if(root->right == NULL) range.second = root->data;

    cout<<"\nRange for "<<root->data<<" = ["<<range.first<<", "<<range.second<<"]";
    if(low <= range.first && range.first <= high && low <= range.second && range.second <= high) {
        count++;
        cout<<"\nFOUND! => Subtree at "<<root->data<<endl;
    } 

    return range;
}

int getCount(node* root, int low, int high) {
    int count = 0;
    getRange(root, low, high, count);
    return count;
}

// ************* DRIVER CODE *************
int main() {
    // Let us construct the BST shown in the above figure
    node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(50);
    root->left->left = newNode(1);
    root->right->left = newNode(40);
    root->right->right = newNode(100);
    /* Let us constructed BST shown in above example
          10
        /    \
      5       50
     /       /  \
    1       40   100   */
    int l = 1;
    int h = 45;
    int ans = getCount(root, l, h);
    cout << "\n\nCount of subtrees in [" << l << ", "<< h << "] is " << ans;
    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node {
public:
    string info;
    node *left = NULL, *right = NULL;
    node(string x) {
        info = x;
    }
};

int eval(node* root) {

    if(root == NULL) return 0;

    if(root->left == NULL && root->right == NULL) {
        return stoi(root->info);
    }

    int leftValue = eval(root->left);
    int rightValue = eval(root->right);

    string operation = root->info;
    
    if(operation == "+") return leftValue + rightValue;
    if(operation == "-") return leftValue - rightValue;
    if(operation == "*") return leftValue * rightValue;
    if(operation == "/") return leftValue / rightValue;

    return stoi(root->info);
}

int main() {
    // create a syntax tree
    node *root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("-4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("20");
    cout << eval(root) << endl;
 
    delete(root);
 
    root = new node("+");
    root->left = new node("*");
    root->left->left = new node("5");
    root->left->right = new node("4");
    root->right = new node("-");
    root->right->left = new node("100");
    root->right->right = new node("/");
    root->right->right->left = new node("20");
    root->right->right->right = new node("2");
 
    cout << eval(root);

    return 0;
}
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Structure of a node of an n-ary tree
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }
    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// height and diameter
pair<int, int> heightAndDiameter(Node* root) {
    if(root == NULL) return {0, 0};

    int maxHeight1 = 0;
    int maxHeight2 = 0;
    int maxDiameter = 0;

    for(Node* child : root->children) {
        auto childHandD = heightAndDiameter(child);
        int childHeight = childHandD.first;
        int childDiameter = childHandD.second;

        if(childHeight > maxHeight1) {
            maxHeight2 = maxHeight1;
            maxHeight1 = childHeight;
        } else if(childHeight > maxHeight2) {
            maxHeight2 = childHeight;
        }
        
        maxDiameter = max(maxDiameter, childDiameter);
    }

    int rootHeight = maxHeight1 + 1;
    int rootDiameter = max(maxHeight1 + maxHeight2 + 1, maxDiameter);

    return {rootHeight, rootDiameter};
}
 
// Function to calculate the diameter
// of the tree
int diameter(Node *root) {
    return heightAndDiameter(root).second;
}
 
// Driver program
int main() {
    /*   Let us create below tree
    *           A
    *         / /  \  \
    *       B  F   D  E
    *      / \     |  /|\
    *     K  J    G  C H I
    *      /\            \
    *    N   M            L
    */
 
    Node *root = new Node('A');
    (root->children).push_back(new Node('B'));
    (root->children).push_back(new Node('F'));
    (root->children).push_back(new Node('D'));
    (root->children).push_back(new Node('E'));
    (root->children[0]->children).push_back(new Node('K'));
    (root->children[0]->children).push_back(new Node('J'));
    (root->children[2]->children).push_back(new Node('G'));
    (root->children[3]->children).push_back(new Node('C'));
    (root->children[3]->children).push_back(new Node('H'));
    (root->children[3]->children).push_back(new Node('I'));
    (root->children[0]->children[0]->children).push_back(new Node('N'));
    (root->children[0]->children[0]->children).push_back(new Node('M'));
    (root->children[3]->children[2]->children).push_back(new Node('L'));
 
    cout << diameter(root) << endl;
 
    return 0;
}
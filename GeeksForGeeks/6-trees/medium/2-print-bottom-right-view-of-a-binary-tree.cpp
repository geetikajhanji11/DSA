/*******************************************************************
LAST NODE OF EACH LAYER OF DIAGONAL TRAVERSAL 
*******************************************************************/

#include<bits/stdc++.h>
using namespace std;

// A binary tree node
struct Node {
	int data;
	Node *left, *right;
	Node(int item) {
		data = item;
		left = right = NULL;
	}
};

// inclusive of root
// keep pushing node and going right  
vector<Node*> getAllRights(Node* root) {
    vector<Node*> rights;
    while(root != NULL) {
        rights.push_back(root);
        root = root->right;
    }
    return rights;
}

// diagonal traverse
vector<int> diagonal(Node *root) {

    vector<int> result;

    // first layer is just all the rightmost nodes of tree
    vector<Node*> prevLayer = getAllRights(root);
    if(!prevLayer.empty()) {
        int lastNode = prevLayer[prevLayer.size() - 1]->data;
        result.push_back(lastNode);
    }

    // for every "prev" node in prevLayer,
    // if prev->left exists, push all right most nodes
    // of prev->left including itself in the next layer vector
    while(!prevLayer.empty()) {
        vector<Node*> currLayer;
        for(Node* prev : prevLayer) {
            if(prev->left != NULL) {
                vector<Node*> temp = getAllRights(prev->left);
                currLayer.insert(currLayer.end(), temp.begin(), temp.end());
            }
        }
        
        if(!currLayer.empty()) {
            int lastNode = currLayer[currLayer.size() - 1]->data;
            result.push_back(lastNode);
        }

        prevLayer = currLayer;
    }

    return result;
}

vector<int> bottomRightView(Node *root) {
    return diagonal(root);
}

// Driver Code
int main() {

	// Node *root = new Node(1);
	// root->left = new Node(2);
	// root->right = new Node(3);
	// root->left->left = new Node(4);
	// root->right->left = new Node(5);
	// root->right->left->right = new Node(6);

    Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->right->left = new Node(5);
	root->right->left->left = new Node(6);

	auto result = bottomRightView(root);

    for(int num : result) cout<<num<<" ";
}

// This code is contributed by Arnab Kundu

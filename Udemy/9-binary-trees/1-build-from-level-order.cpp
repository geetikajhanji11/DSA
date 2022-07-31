/**************************************************************

BINARY TREE

**************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

// binary tree node class
class node {
public:
    int data;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// input: 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree() {
    int data;
    cin>>data;
    
    if(data == -1) return NULL;
    
    node *newNode = new node(data);
    newNode->left = buildTree();
    newNode->right = buildTree();
    
    return newNode;
}


// level order print (LINE WISE PRINT)
void levelOrderLine(node* root) {
    
    cout<<"\nLEVEL ORDER (LINE WISE PRINT)\n";
    
    queue<node*> Q;
    Q.push(root);
    Q.push(NULL);
    
    while(!Q.empty()) {
        
        node *n = Q.front();
        if(n == NULL) {
            cout<<"\n";
            Q.pop();
            
            if(!Q.empty()) Q.push(NULL);
            
            continue;
        }
        
        cout<<n->data<<" ";
        if(n->left != NULL) Q.push(n->left);
        if(n->right != NULL) Q.push(n->right);
        
        Q.pop();
    }
    
    
}

node* buildTreeFromLevel(vector<int> arr) {
    vector<node*> nodeArr;
    for(int data : arr) {
        if(data == -1) {
            nodeArr.push_back(NULL);
            continue;
        }
        node* newNode = new node(data);
        nodeArr.push_back(newNode);
    }
    
    int pos = 0;
    for(node* currNode : nodeArr) {
        
        if(pos >= nodeArr.size()) break;
        
        if(currNode == NULL) {
            continue;
        }
        
        currNode->left = nodeArr[pos + 1];
        currNode->right = nodeArr[pos + 2];
        pos = pos + 2;
    }
    
    
    return nodeArr[0];
    
    
}

/* 

----------------------------
Implement Level Order Build
for the tree
PRATEEK SOLUTION
----------------------------

node* levelOrderBuild(){

	int d;
	cin>>d;

	node* root = new node(d);

	queue<node*> q;
	q.push(root);


	while(!q.empty()){
		node* current = q.front();
		q.pop();

		int c1, c2;
		cin>> c1 >> c2;

		if(c1!=-1){
			current->left = new node(c1);
			q.push(current->left);
		}
		if(c2!=-1){
			current->right = new node(c2);
			q.push(current->right);
		}
	}
	return root;
}

*/

// *************** MY NEW SOLUTION *******************
node* construct(vector<int> arr) {
    queue<node*> q;
    node* root = new node(arr[0]);
    q.push(root);

    int i = 1;
    while(i != arr.size()) {
        node* curr = q.front();
        q.pop();
        if(curr == NULL) {
            i += 2;
            continue;
        }

        node* left_node = arr[i] != -1 ? new node(arr[i]) : NULL;
        curr->left = left_node;
        q.push(left_node);
        i++;

        node* right_node = arr[i] != -1 ? new node(arr[i]) : NULL;
        curr->right = right_node;
        q.push(right_node);
        i++;

    }
    return root;
}
// ****************************************************************


int main() {

    vector<int> arr{
        1, 2, 3, 4, 5, -1, 6, -1, -1, 7, -1, -1, -1, -1, -1
    };
    // node *root = buildTreeFromLevel(arr);
    node* root = construct(arr);
    levelOrderLine(root);

	return 0;
}
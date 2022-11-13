/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {

    static bool customSort(pair<int, int> p1, pair<int, int> p2) {
        return p1.first < p2.first;
    }

    int minSwapsToSortArray(vector<int> &arr) {
        int n = arr.size();

        vector<pair<int, int>> num_pos;
        vector<int> visited(arr.size(), false);

        for(int i=0; i<n; i++) {
            num_pos.push_back({arr[i], i});
        }
        sort(num_pos.begin(), num_pos.end(), customSort);

        int swaps = 0;
        for(int i=0; i<n; i++) {

            if(visited[i] || num_pos[i].second == i) {
                continue;
            }

            int j = i;
            int cycleNodes = 0;
            while(!visited[j]) {
                visited[j] = true;
                j = num_pos[j].second;
                cycleNodes++;
            }

            if(cycleNodes > 0) {
                swaps += (cycleNodes - 1);
            }
            
        }
        return swaps;
    }

public:
    int minimumOperations(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);

        int result = 0;
        while(!q.empty()) {
            int size = q.size();

            vector<int> arr;
            while(size != 0) {
                TreeNode* curr = q.front(); q.pop();
                arr.push_back(curr->val);
                if(curr->left != NULL) q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
                size--;
            }

            result += minSwapsToSortArray(arr);

        }

        return result;

    }
};
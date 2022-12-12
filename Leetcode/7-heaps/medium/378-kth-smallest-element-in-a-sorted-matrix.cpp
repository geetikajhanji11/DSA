/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// **************** BINARY SEARCH ****************
class Solution {
    int countNumbersLessOrEqual(vector<vector<int>>& matrix, int target) {
        int count = 0;

        int col = matrix[0].size() - 1;
        for(int row=0; row<matrix.size(); row++) {
            while(col >= 0 && matrix[row][col] > target) col--;
            count += (col + 1);
        }

        return count;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = matrix[0][0];
        int high = matrix[rows-1][cols-1];

        int result = -1;

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(countNumbersLessOrEqual(matrix, mid)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return result;
    }
};

// **************** HEAP SOLUTION ****************
class Element {
public:
    int num;
    int i;
    int arrayId;
    Element(int num, int i, int arrayId) {
        this->num = num;
        this->i = i;
        this->arrayId = arrayId;
    }
};

class Compare {
public:
    bool operator()(Element e1, Element e2) {
        return e1.num > e2.num;
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<Element, vector<Element>, Compare> minHeap;

        for(int arrayId=0; arrayId<matrix.size(); arrayId++) {
            minHeap.push(Element(matrix[arrayId][0], 0, arrayId));
        }

        while(k > 1) {
            Element curr = minHeap.top(); minHeap.pop();
            k--;

            if(curr.i + 1 == matrix[curr.arrayId].size()) {
                continue;
            }

            minHeap.push(
                Element(
                    matrix[curr.arrayId][curr.i + 1], 
                    curr.i + 1, 
                    curr.arrayId
                )
            );
        }
        
        return minHeap.top().num;
    }
};
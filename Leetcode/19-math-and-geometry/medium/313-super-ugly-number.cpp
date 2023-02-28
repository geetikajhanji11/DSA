/*******************************************************************
DID NOT PASS LEETCODE
BUT ENOUGH FOR INTERVIEW
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** DISCUSS SOLUTION ***********************

class Node {
public:
    long long result;
    int prime;
    int index;
    Node(long long res, int n, int i) {
        result = res;
        prime = n;
        index = i;
    }
};

class Comapre {
public:
    bool operator()(Node &n1, Node &n2) {
        return n1.result > n2.result;
    }
};

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        priority_queue<Node, vector<Node>, Comapre> minHeap;

        vector<int> uglyNumbers(n+1);
        uglyNumbers[0] = 1;

        for(int prime : primes) {
            minHeap.push(Node(prime, prime, 0));
        }

        int i = 1;
        while(i < n) {
            Node node = minHeap.top(); minHeap.pop();

            // we found a new ugly number
            // now put it in array
            if(node.result != uglyNumbers[i-1]) {
                uglyNumbers[i] = node.result;
                i++;
            }

            long long newResult = node.prime * uglyNumbers[node.index + 1];
            minHeap.push(Node(newResult, node.prime, node.index + 1));

        }

        return uglyNumbers[n - 1];
    }
};
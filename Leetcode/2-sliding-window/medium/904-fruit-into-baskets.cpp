/*******************************************************************
Find out the longest length of subarrays with at most 2 different numbers?
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int maxFruits = 0;

        int lastFruit = -1;
        int secondLastFruit = -1;

        // consecutive count of last fruit
        // eg [1, 0, 1, 1, 1, 2, 2, 2]
        // after 10111, we reach "2", which is a new fruit
        // so consecutive count of "1" before "2" is = 3
        int lastFruitCount = 0; 
        
        int currFruits = 0;
        for(int fruit : fruits) {

            if(fruit == lastFruit || fruit == secondLastFruit) {
                currFruits++;
            } else {
                currFruits = lastFruitCount + 1; // + 1 for new fruit
            }

            maxFruits = max(maxFruits, currFruits);

            if(fruit == lastFruit) {
                lastFruitCount++;
            } else {
                lastFruitCount = 1;
                secondLastFruit = lastFruit;
                lastFruit = fruit;
            }
        
        }

        return maxFruits;
    }
};

// ********** generalizing **************
class Solution {
public:
    int totalFruit(vector<int> &tree) {

        unordered_map<int, int> count;
        int i = 0;
        int j = 0;
        int maxFruits = 0;
        for (j=0; j<tree.size(); j++) {
            count[tree[j]]++;
            while (count.size() > 2) {
                count[tree[i]]--;
                if(count[tree[i]] == 0) {
                    count.erase(tree[i]);
                }
                i++;
            }
            maxFruits = max(maxFruits, j - i + 1);
        }

        // window size
        return maxFruits;
    }
};
/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// O(nlogn) sorting
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int sum = 0;
        int ctr = 0;
        for(int cost : costs) {
            if(sum + cost > coins) return ctr;
            sum += cost; 
            ctr++;
        }

        return ctr;
    }
};

// O(n + m) counting sort
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxCost + 1, 0);

        for(int cost : costs) {
           freq[cost]++;
        }

        long long sum = 0;
        int ctr = 0;

        for(int i=0; i<freq.size(); i++) {
            int cost = i;
            int f = freq[cost];

            if(f == 0) continue;

            long long add = f * cost;

            if(sum + add > coins) {
                for(int j=0; j<f; j++) {
                    if(sum + cost > coins) {
                        return ctr;
                    }
                    sum += cost;
                    ctr++;
                }
            } 
            
            else if(sum + add < coins) {
                sum += add;
                ctr += f;
            } 
            
            else if(sum + add == coins) {
                sum += add;
                ctr += f;
                return ctr;
            }

        }

        return ctr;
    }
};
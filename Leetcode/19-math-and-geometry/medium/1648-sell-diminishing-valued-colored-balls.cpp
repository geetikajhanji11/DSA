/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********* CORRECT *********
#define MOD 1000000007;
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        int n = inventory.size();

        sort(inventory.begin(), inventory.end());
        long long totalProfit = 0; 

        for(int i=n-1; i>=0; i--) {

            long long diff = inventory[i] - (i > 0 ? inventory[i-1] : 0);

            long long ballsWeCanTake = diff * (n - i);
            long long ordersFullfilled = min((long long)orders, ballsWeCanTake);

            // calculate profit
            long long r = inventory[i];
            long long rightSum = r * (r + 1) / 2;

            long long l = r - ordersFullfilled / (n - i);
            long long leftSum = l * (l + 1) / 2;

            totalProfit += (rightSum - leftSum) * (n - i);
            totalProfit %= MOD;
            totalProfit += l * (ordersFullfilled % (n - i));
            totalProfit %= MOD;

            orders -= ordersFullfilled;

            if(orders == 0) break;

        }

        return totalProfit;
    }
};

// ********* LOGIC CORRECT (BUT TLE) *********
class Solution {
public:
    int maxProfit(vector<int>& inventory, int orders) {
        priority_queue<int> maxHeap;

        for(int num : inventory) maxHeap.push(num);

        int total = 0;
        while(orders != 0) {
            int val = maxHeap.top(); maxHeap.pop();
            if(val - 1 != 0) {
                maxHeap.push(val - 1);
            }
            total += val;
            total %= MOD;
            orders--;
        }

        return total;
    }
};
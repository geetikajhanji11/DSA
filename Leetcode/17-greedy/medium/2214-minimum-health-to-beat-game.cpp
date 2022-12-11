/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************* MY SOLUTION *************
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {

        // sum of all damages
        long long totalDamage = accumulate(damage.begin(), damage.end(), 0L);

        // no armor means, we have to sum all damages and + 1
        // and return it 
        if(armor == 0) return totalDamage + 1;

        // for every level, calculate minimum health
        // needed if we use armour in that level
        long long minHealth = totalDamage + 1;

        for(int currDamage : damage) {
            int damageDeflected = 0;
            if(armor >= currDamage) {
                damageDeflected = currDamage;
            } else {
                damageDeflected = armor;
            }
            minHealth = min(minHealth, totalDamage - damageDeflected + 1);
        }

        return minHealth;
    }
};

// ************* GREEDY SOLUTION *************
// We greedily use the armor at the level with the greatest damage. 
// Without armor, we need [1 + sum(A)] min health. 
// The armor can take damange of min(max(A), armor), 
// saving us this amount of health. So in total, 
// we just need 1 + sum(A) - min(max(A), armor).
class Solution {
public:
    long long minimumHealth(vector<int>& damage, int armor) {
        int maxDamage = *max_element(damage.begin(), damage.end());
        long long totalDamage = accumulate(damage.begin(), damage.end(), 0L);
        return 1 + totalDamage - min(maxDamage, armor);
    }
};

// ************* DP SOLUTION *************
class Solution {
public:
    long long minimumHealth(vector<int>& A, int armor) {
        long yes = 1, no = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            long newYes = min(no + max(0, A[i] - armor), yes + A[i]);
            long newNo = no + A[i];
            yes = newYes, no = newNo;
        }
        return min(yes, no);
    }
};

int main() {

    // 10
    vector<int> damage = {3,3,3};
    int armour = 0;
 
    // 13
    // vector<int> damage = {2,7,4,3};
    // int armour = 4;

    // 10
    // vector<int> damage = {2,5,3,4};
    // int armour = 7;

    Solution s;
    cout<<s.minimumHealth(damage, armour);

    return 0;
}

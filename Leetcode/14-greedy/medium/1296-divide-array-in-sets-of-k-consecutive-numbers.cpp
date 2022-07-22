/*******************************************************************
SAME AS 846 - HAND OF STRAIGHTS
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossibleDivide(vector<int>& nums, int k) {
    int n = nums.size();
    if(n % k != 0) return false;

    map<int, int> m;
    for(int num : nums) m[num]++;

    while(!m.empty()) {
        int curr = m.begin()->first;
        for(int i=0; i<k; i++) {
            int num = curr + i;
            if(m.find(num) == m.end()) return false;
            m[num]--;
            if(m[num] < 1) m.erase(num);
        }
    }
    return true;
}

int main() {

    return 0;
}
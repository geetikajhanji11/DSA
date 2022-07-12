#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    
    unordered_map<int, int> count;

    int cumulative_sum = 0;
    for(int num : nums) {
        cumulative_sum += num;
        int remainder = cumulative_sum % k;
        if(remainder < 0) { // remainder is -ve, add k to make it positive
            remainder += k;
        }
        count[remainder]++;
    }

    int result = 0;
    for(auto it=count.begin(); it!=count.end(); it++) {
        int remainder = it->first;
        int freq = it->second;

        if(freq >= 2) {
            // nC2 = (n * (n-1)) / 2
            result += ((freq * (freq-1)) / 2);
        }

        if(remainder == 0) {
            result += freq;
        }

    }

    return result;

}

int main() {

    return 0;
}
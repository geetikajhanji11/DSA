
#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int>& nums) {
    
    int xor_of_array = 0;
    for(int num : nums) {
        xor_of_array = xor_of_array ^ num;
    }

    int total_xor = 0;
    for(int i=0; i<=nums.size(); i++) {
        total_xor = total_xor ^ i;
    }

    return xor_of_array ^ total_xor;
}

int main() {

    return 0;
}
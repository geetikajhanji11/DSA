#include<bits/stdc++.h>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
    vector<int> result;
    for(int num : nums) {
        num = abs(num);
        if(nums[num-1] > 0) nums[num-1] *= -1;
        else result.push_back(num);
    }
    return result;
}

int main() {

    return 0;
}
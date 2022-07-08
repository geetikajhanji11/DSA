#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

// given an array containing n integers, and a target, find 2 distinct integers that can pair up to form target sum. 
vector<int> twoSum(vector<int> arr, int target){
    
    vector<int> result;

    // hash set method (n)
    unordered_set<int> hashSet;
    for(int num : arr) {
        int diff = target - num;
        if(hashSet.find(diff) != hashSet.end()) {
            result.push_back(diff);
            result.push_back(num);
        } 
        hashSet.insert(num);
    }

    // sorting method (nlogn)
    /*
    sort(arr.begin(), arr.end());
    int left = 0;
    int right = arr.size() - 1;
    while(left < right) {
        int sum = arr[left] + arr[right]; 
        if(sum == target) {
            result.push_back(arr[left]);
            result.push_back(arr[right]);
            left++;
            right--;
        } else if(sum < target) {
            left++;
        } else {
            right--;
        }
    }
    */

    return result;
}

int main() {

    vector<int> arr{10, 5, 2, 2, -1, 3, -6, 9 , 11};
	int S = 4;

	auto p = twoSum(arr,S);
	if(p.size()==0){
		cout<<"No such pair";
	}
	else {
        for(int i=0; i<p.size(); i=i+2) {
            cout<<p[i]<<" + "<<p[i+1]<<endl;
        }
	}

    return 0;
}

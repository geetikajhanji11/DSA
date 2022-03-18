/******************************************************************************

COMMON ELEMENTS

*******************************************************************************/
#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> commonElements(vector<int> v1, vector<int> v2){

    unordered_set<int> set1;
    for(int num : v1) {
        set1.insert(num);
    }
    
    vector<int> result;
    for(int num : v2) {
        if(set1.find(num) != set1.end()) {
            result.push_back(num);
        }
    }
    
    return result;
}

int main() {
    
    vector<int> arr1{1, 45, 54, 71, 76, 12};
    vector<int> arr2{1, 7, 5, 4, 6, 12};
    
    vector<int> result = commonElements(arr1, arr2);
    for(int num : result) {
        cout<<num<<" ";
    }
    
    return 0;
}

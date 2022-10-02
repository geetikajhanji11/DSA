/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> triplets(vector<int> &arr) {

    int n = arr.size();

    vector<vector<int>> result;

    vector<int> squares;
    for(int num : arr) {
        squares.push_back(num * num);
    }

    sort(squares.begin(), squares.end());

    for(int i=n-1; i>=2; i--) {
        int a = squares[i];
        int left = 0;
        int right = i - 1;
        while(left < right) {
            int sum = squares[left] + squares[right];
            if(sum < a) {
                left++;
            } else if(sum > a) {
                right--;
            } else {
                result.push_back({
                    (int) sqrt(squares[i]), 
                    (int) sqrt(squares[left]), 
                    (int) sqrt(squares[right])
                });
                left++;
                right--;
            }
        }
    }

    return result;

}

int main() {

    vector<int> arr = {3, 1, 4, 6, 5};
    auto res = triplets(arr);

    for(auto v : res) {
        for(int num : v) cout<<num<<", ";
        cout<<endl;
    }

    return 0;
}
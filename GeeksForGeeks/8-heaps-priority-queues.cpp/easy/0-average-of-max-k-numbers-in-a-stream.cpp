/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Average {

    priority_queue<int, vector<int>, greater<int>> min_heap;
    int sum;
    int k;

    public:

    Average(int n, int k, vector<int> arr) {
        this->k = k;
        this->sum = 0;
        for(int num : arr) {
            if(min_heap.size() < k) {
                min_heap.push(num);
                sum += num;
            } else {
                if(num > min_heap.top()) {
                    sum = sum - min_heap.top() + num;
                    min_heap.pop();
                    min_heap.push(num);
                }
            }
        }
    }

    float getAverage(int num) {
        if(num > min_heap.top()) {
            sum = sum - min_heap.top() + num;
            min_heap.pop();
            min_heap.push(num);
        }
        return (float) ((float)sum / (float)k);
    }

};

vector<float> averageOfMaxKNumbers(int n, int k, vector<int> arr, vector<int> queries) {

    Average a(n, k, arr);

    vector<float> result;
    for(int q : queries) {
        result.push_back(a.getAverage(q));
    }
    return result;
}


int main() {

    int n = 4;
    int k = 3;
    vector<int> arr = {1,2,3,4};
    vector<int> queries = {7, 2, 1, 5};

    auto result = averageOfMaxKNumbers(n, k, arr, queries);
    for(float num : result) {
        cout<<num<<endl;
    }


    return 0;
}
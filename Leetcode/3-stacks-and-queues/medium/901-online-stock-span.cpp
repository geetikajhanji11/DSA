/*******************************************************************
MONOTONICALLY DECREASING STACK
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class StockSpanner {
    int i;
    stack<pair<int, int>> s; // {index, stock price}

public:

    StockSpanner() {
        this->i = 0;
    }
    
    int next(int price) {
        while(!s.empty() && price >= s.top().second) {
            s.pop();
        }
        
        int ans;
        if(s.empty()) ans = i - (-1);
        else ans = i - s.top().first;

        s.push({i, price});
        i++;

        return ans;

    }
};
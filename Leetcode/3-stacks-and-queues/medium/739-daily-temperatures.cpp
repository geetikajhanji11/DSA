/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {

    int n = temperatures.size();
    vector<int> result(n, 0);
    stack<int> s; // colder temperature up

    s.push(n-1);
    int i = n-2;

    while(i >= 0) {

        // current temperature is strictly less than 
        // the temperature at the top of the stack
        if(!s.empty() && temperatures[i] < temperatures[s.top()]) {
            result[i] = s.top() - i;
            s.push(i);
        } 
        
        // pop from stack until the current temperature is 
        // strictly less than the temperature at top of the stack
        else {
            while(!s.empty() && temperatures[i] >= temperatures[s.top()]) {
                s.pop();
            }
            if(s.empty()) {
                result[i] = 0;
            } else {
                result[i] = s.top() - i;
            }
            s.push(i);
        }
        i--;
    }

    return result;

}

int main() {

    return 0;
}
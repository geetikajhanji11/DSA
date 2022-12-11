/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************ MAIN LOGIC ************ 
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> increasingStack;
        int result = 0;

        for(int i=0; i<=n; i++) {
            while(!increasingStack.empty() && (i == n || arr[increasingStack.top()] > arr[i])) {
                int pop_i = increasingStack.top(); increasingStack.pop();
                int prev_i = increasingStack.empty() ? -1 : increasingStack.top(); 
                int next_i = i;

                int leftElements = pop_i - prev_i;
                int rightElements = next_i - pop_i;

                int contributions = leftElements * rightElements * arr[pop_i];
                result += contributions;
            }
            increasingStack.push(i);
        }

        return result;
    }
};

// ************ LONG LONG => TO PASS ON LC ************ 
class Solution {
    int MOD = pow(10, 9) + 7;
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        stack<int> increasingStack;
        int result = 0;

        for(int i=0; i<=n; i++) {
            while(!increasingStack.empty() && (i == n || arr[increasingStack.top()] > arr[i])) {
                int pop_i = increasingStack.top(); increasingStack.pop();
                int prev_i = increasingStack.empty() ? -1 : increasingStack.top(); 
                int next_i = i;

                long long leftElements = pop_i - prev_i;
                long long rightElements = next_i - pop_i;

                long long contributions = leftElements * rightElements * (long long) arr[pop_i];
                int x = contributions % MOD;
                result = (result + x) % MOD;
            }

            increasingStack.push(i);
        }

        return result;
    }
};
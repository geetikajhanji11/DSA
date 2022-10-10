/*******************************************************************
DID NOT UNDERSTAND
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *********** LOGIC CORRECT BUT TLE ***********
class Solution {

    int sequences(int i, int prevNum, vector<bool> visited, string &s, int &n) {

        if(i == s.length()) return 1;

        int ans = 0;
        for(int num=0; num<=n; num++) {

            if(s[i] == 'D' && !visited[num] && prevNum > num) {
                visited[num] = true;
                ans += sequences(i+1, num, visited, s, n);
                visited[num] = false;
            }

            if(s[i] == 'I' && !visited[num] && prevNum < num) {
                visited[num] = true;
                ans += sequences(i+1, num, visited, s, n);
                visited[num] = false;
            }
        }

        return ans;
    }

public:
    int numPermsDISequence(string s) {
        
        int n = s.length();

        vector<bool> visited(n+1, false);

        int ans = 0;
        for(int num=0; num<=n; num++) {
            visited[num] = true;
            ans += sequences(0, num, visited, s, n);
            visited[num] = false;
        }

        return ans;
    }
};
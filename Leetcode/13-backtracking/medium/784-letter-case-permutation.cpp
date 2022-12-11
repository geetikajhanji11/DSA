/*******************************************************************
 * BFS SOLUTION

Let's use "a1b2c3" as an example, 
and curly braces below indicate the inside part is(are) new string(s) 
after togglling operation.

"a1b2c3"  
initialization

"a1b2c3" {"A1b2c3} 
i = 0, a toggled to A

"a1b2c3" "A1b2c3"
i = 1, ignore '1', which is a digit,

"a1b2c3" "A1b2c3" {"a1B2c3" "A1B2c3"} 
i = 2, b toggled to B

"a1b2c3" "A1b2c3" "a1B2c3" "A1B2c3 
i = 3, ignore '2', which is a digit,

"a1b2c3" "A1b2c3" "a1B2c3" "A1B2c3" {"a1b2C3" "A1b2C3" "a1B2C3" "A1B2C3"}  
i = 4, c toggled to C

"a1b2c3" "A1b2c3" "a1B2c3" "A1B2c3" "a1b2C3" "A1b2C3" "a1B2C3" "A1B2C3" 
i = 5, ignore 3, which is a digit.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// *************** DFS SOLUTION ***************
class Solution {

    void dfs(int i, string curr, string &s, vector<string> &result) {
        if(i == s.length()) {
            result.push_back(curr);
            return;
        }

        if(isdigit(s[i])) {
            dfs(i+1, curr + s[i], s, result);
            return;
        }

        char lower = tolower(s[i]);
        char upper = toupper(s[i]);

        dfs(i+1, curr + lower, s, result);
        dfs(i+1, curr + upper, s, result);
    }

public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        dfs(0, "", s, result);
        return result;
    }
};

// *************** BFS SOLUTION ***************
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        
        vector<string> result = {s};

        for(int i=0; i<s.length(); i++) {

            if(isdigit(s[i])) continue;

            int resultSize = result.size();
            for(int j=0; j<resultSize; j++) {
                string curr = result[j];
                curr[i] ^= (1 << 5); // toggle character at curr[i]
                result.push_back(curr);
            }

        }

        return result;

    }
};

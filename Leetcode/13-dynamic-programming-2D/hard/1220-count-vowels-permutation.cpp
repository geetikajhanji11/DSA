/*******************************************************************

Each vowel 'a' may only be followed by an 'e'.
    => "ae"

Each vowel 'e' may only be followed by an 'a' or an 'i'.
    => "ea", "ei"

Each vowel 'i' may not be followed by another 'i'.
    => "ia", "ie", "io", "iu"

Each vowel 'o' may only be followed by an 'i' or a 'u'.
    => "oi", "ou"

Each vowel 'u' may only be followed by an 'a'.
    => "ua"


----------- THIS MEANS -----------
START BUILDING STRING FROM THE END... I.E. LENGTH 1

-----> ending with a = "ea", "ia", "ua"     [e, i, u]
-----> ending with e = "ae", "ie"           [a, i]
-----> ending with i = "ei", "oi"           [e, o]
-----> ending with o = "io"                 [i]
-----> ending with u = "iu", "ou",          [i, o]

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ***************** MAIN LOGIC *****************
class Solution {

public:
    int countVowelPermutation(int n) {

        unordered_map<char, int> idx;
        idx['a'] = 0;
        idx['e'] = 1;
        idx['i'] = 2;
        idx['o'] = 3;
        idx['u'] = 4;

        vector<vector<int>> dp(5, vector<int>(n+1, 0));

        // length 1 string...
        dp[idx['a']][1] = 1;
        dp[idx['e']][1] = 1;
        dp[idx['i']][1] = 1;
        dp[idx['o']][1] = 1;
        dp[idx['u']][1] = 1;

        // rest... build from length 2 to length n
        for(int i=2; i<=n; i++) {
            dp[idx['a']][i] += dp[idx['e']][i-1] + dp[idx['u']][i-1] + dp[idx['i']][i-1];
            dp[idx['e']][i] += dp[idx['a']][i-1] + dp[idx['i']][i-1];
            dp[idx['i']][i] += dp[idx['e']][i-1] + dp[idx['o']][i-1];
            dp[idx['o']][i] += dp[idx['i']][i-1];
            dp[idx['u']][i] += dp[idx['i']][i-1] + dp[idx['o']][i-1];
        }

        return (
            dp[idx['a']][n] + 
            dp[idx['e']][n] + 
            dp[idx['i']][n] + 
            dp[idx['o']][n] + 
            dp[idx['u']][n]
        );

    }
};

// ***************** passed on LC ***************** 
class Solution {

    int MOD = pow(10, 9) + 7;

public:
    int countVowelPermutation(int n) {

        unordered_map<char, int> idx;
        idx['a'] = 0;
        idx['e'] = 1;
        idx['i'] = 2;
        idx['o'] = 3;
        idx['u'] = 4;

        vector<vector<int>> dp(5, vector<int>(n+1, 0));

        dp[idx['a']][1] = 1;
        dp[idx['e']][1] = 1;
        dp[idx['i']][1] = 1;
        dp[idx['o']][1] = 1;
        dp[idx['u']][1] = 1;

        for(int i=2; i<=n; i++) {
            dp[idx['a']][i] += ((dp[idx['e']][i-1] % MOD + dp[idx['u']][i-1] % MOD) % MOD + dp[idx['i']][i-1] % MOD) % MOD;
            dp[idx['e']][i] += (dp[idx['a']][i-1] + dp[idx['i']][i-1]) % MOD;
            dp[idx['i']][i] += (dp[idx['e']][i-1] + dp[idx['o']][i-1]) % MOD;
            dp[idx['o']][i] += (dp[idx['i']][i-1]) % MOD;
            dp[idx['u']][i] += (dp[idx['i']][i-1] + dp[idx['o']][i-1]) % MOD;
        }

        return ((((dp[idx['a']][n] + dp[idx['e']][n]) % MOD + dp[idx['i']][n]) % MOD + dp[idx['o']][n]) % MOD + dp[idx['u']][n]) % MOD;

    }
};
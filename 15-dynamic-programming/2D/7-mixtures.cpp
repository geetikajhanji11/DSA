/*******************************************************************
 * MIXTURES
 * 
 * Harry Potter has n mixtures in front of him, arranged in a row. 
 * Each mixture has one of 100 different colors (colors have numbers 
 * from 0 to 99). He wants to mix all these mixtures together. 
 * At each step, he is going to take two mixtures that stand next 
 * to each other and mix them together, and put the resulting 
 * mixture in their place. When mixing two mixtures of colors a and 
 * b, the resulting mixture will have the color (a+b) mod 100. 
 * Also, there will be some smoke in the process. The amount of 
 * smoke generated when mixing two mixtures of colors a and b is 
 * a*b. Find out what is the minimum amount of smoke that Harry 
 * can get when mixing all the mixtures together.
 * 
 * Input:
 * 
 *      2
 *      18 19
 * 
 *      3
 *      40 60 20
 * 
 * Output:
 *      342
 *      2400
 * 
 *      In the second test case, there are two possibilities:
 * 
 *      => first mix 40 and 60 (smoke: 2400), getting 0, 
 *          then mix 0 and 20 (smoke: 0); total amount of smoke is 2400 
 * 
 *      => first mix 60 and 20 (smoke: 1200), getting 80, 
 *          then mix 40 and 80 (smoke: 3200); total amount of smoke 
 *          is 4400
 * 
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long long sum(int i, int j, vector<int> v) {
    
    long long ans = 0;
    for(int k=i; k<=j; k++) {
        ans += v[k];
        ans %= 100;
    }
    return ans;
}

long long mixtures_smoke(int i, int j, vector<int> mixtures, vector<vector<long long>> &dp) {
    
    if(i >= j) return 0;
    if(dp[i][j] != -1) return dp[i][j];

    long long smoke = INT_MAX;
    for(int k=i; k<j; k++) {
        long long smoke_before_partition = mixtures_smoke(i, k, mixtures, dp);
        long long smoke_after_partition = mixtures_smoke(k+1, j, mixtures, dp);
        long long cumulative_sum_product = sum(i, k, mixtures) * sum(k+1, j, mixtures);

        long long curr_smoke = smoke_before_partition + smoke_after_partition + cumulative_sum_product;
        
        smoke = min(smoke, curr_smoke);
    }

    return dp[i][j] = smoke;
}


long long minimumSmoke(vector<int> v){
    int n = v.size();
    vector<vector<long long>> dp(n+1, vector<long long>(n+1, -1));

    return mixtures_smoke(0, n-1, v, dp);
}

int main() {

    vector<int> v = {40, 60, 20};
    cout<<minimumSmoke(v);
    return 0;
}
/*******************************************************************
 * SELLING WINES
 * 
 * There is a collection of N wines placed linearly on shelf, the
 * price of the ith wine is wines[i].
 * Since wines get better every year, suppose today is the year 1,
 * on the year "y" the price of the ith wine will be y * wines[i].
 * that is, y-times the value that current year.
 * You want to sell all the wines you have, but you want to sell
 * exactly one wine per year, starting this year. On more 
 * constraint - on each year, you can sell either the leftmost
 * or the rightmost wine without re-ordering. Find the maximum
 * profit you can get if you sell all the wines in the optimal order.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int selling_wines(int i, int j, vector<int> wines, int year) {
    
    if(i == j) return wines[i] * year;

    // if we sell the leftmost wine
    int left_profit = year*wines[i] + selling_wines(i+1, j, wines, year+1);
    
    // if we sell the rightmost wine
    int right_profit = year*wines[j] + selling_wines(i, j-1, wines, year+1);

    // return the max of the two
    return max(left_profit, right_profit);

}

int selling_wines_top_down(int i, int j, vector<int> wines, int year, vector<vector<int>> &dp) {
    
    if(i > j) return 0;
    if(dp[i][j] != 0) return dp[i][j];

    // if we sell the leftmost wine
    int left_profit = year*wines[i] + selling_wines_top_down(i+1, j, wines, year+1, dp);
    
    // if we sell the rightmost wine
    int right_profit = year*wines[j] + selling_wines_top_down(i, j-1, wines, year+1, dp);

    // return the max of the two
    return dp[i][j] = max(left_profit, right_profit);
}

int selling_wines_bottom_up(vector<int> wines) {
    int n = wines.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));

    // iterating from bottom row to top row
    // go left to right in each row
    for(int i=n-1; i>=0; i--) {
        for(int j=0; j<n; j++) {
            
            // last bottle left to sell
            if(i == j) {
                dp[i][j] = n * wines[i];
            }

            // other case
            else if(i < j) {
                int year = n - (j - i);
                int pick_left = wines[i] * year + dp[i+1][j];
                int pick_right = wines[j] * year + dp[i][j-1];
                dp[i][j] = max(pick_left, pick_right);
            }
        }
    }

    // answer stored in top right
    cout<<"\nBottom-Up DP Matrix\n";
    for(auto v : dp) {
        for(int num : v) {
            cout<<num<<" ";
        }
        cout<<endl;
    }
    return dp[0][n-1];
}

int main() {

    vector<int> wines = {2, 3, 5, 1, 4};
    int i = 0;
    int j = wines.size() - 1;
    int year = 1;

    cout<<"\nNormal Recursion = "<<selling_wines(i, j, wines, year);

    vector<vector<int>> dp(wines.size(), vector<int>(wines.size(), 0));
    cout<<"\n\nTop-Down DP = "<<selling_wines_top_down(i, j, wines, year, dp);
    cout<<"\nTop-Down DP Matrix\n";
    for(auto v : dp) {
        for(int num : v) {
            cout<<num<<" ";
        }
        cout<<endl;
    }

    int ans = selling_wines_bottom_up(wines);
    cout<<"Bottom-Up DP = "<<ans;

    return 0;
}
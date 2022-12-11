/*******************************************************************
class Solution {
public:
    int rec(vector<int> &days, vector<int> &costs, int i, vector <bool> map, vector <int>& memo) {
        if( i > 365)
            return 0;
        if(memo[i] != -1)
            return memo[i]; // Already calculated
        if(!map[i])
            return memo[i] = rec(days, costs, i+1, map, memo);
        return memo[i] = min({
            costs[0] + rec(days, costs, i+1, map, memo),
            costs[1] + rec(days, costs, i+7, map, memo),
            costs[2] + rec(days, costs, i+30, map, memo)
        });
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector <bool> map(366, false);
        vector <int> memo(366, -1);
        for(auto x: days)
            map[x] = true;
        int x = rec(days, costs, 0, map, memo);
        return x;
    }
};
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {

    int getNextDayIndex(int i, int pass, vector<int>& days) {
        int j = i;
        while(j < days.size() && days[j] < days[i] + pass) {
            j++;
        }
        return j;
    }

    int minCost(int i, vector<int>& days, vector<int>& costs, vector<int> &dp) {
        if(i == days.size()) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;
        int j;

        // day 1 pass [0]
        j = getNextDayIndex(i, 1, days);
        ans = min(ans, costs[0] + minCost(j, days, costs, dp));

        // day 7 pass [1]
        j = getNextDayIndex(i, 7, days);
        ans = min(ans, costs[1] + minCost(j, days, costs, dp));

        // day 30 pass [2]
        j = getNextDayIndex(i, 30, days);
        ans = min(ans, costs[2] + minCost(j, days, costs, dp));

        return dp[i] = ans;
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n, -1);
        return minCost(0, days, costs, dp);
    }
};

// **************** MY DP SOLUTION ****************
class Solution {

    int minCost(int i, int passEndDay, vector<int>& days, vector<int>& costs, vector<vector<int>> &dp) {
        if(i == days.size()) return 0;
        
        if(passEndDay > 365) return 0;

        if(dp[i][passEndDay] != -1) return dp[i][passEndDay];

        int currDay = days[i];
        if(currDay < passEndDay) {
            return minCost(i+1, passEndDay, days, costs, dp);
        }

        // purchase a ticket
        int day1 = costs[0] + minCost(i+1, currDay + 1, days, costs, dp);
        int day7 = costs[1] + minCost(i+1, currDay + 7, days, costs, dp);
        int day30 = costs[2] + minCost(i+1, currDay + 30, days, costs, dp);

        return dp[i][passEndDay] = min(day1, min(day7, day30));
    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<vector<int>> dp(n, vector<int>(365 + 1, -1));
        return minCost(0, 0, days, costs, dp);
    }
};


// **************** RECURSIVE SOLUTION ****************
class Solution {

    int minCost(int i, int passEndDay, vector<int>& days, vector<int>& costs) {
        if(i == days.size()) return 0;

        int currDay = days[i];
        if(currDay < passEndDay) {
            return minCost(i+1, passEndDay, days, costs);
        }

        // purchase a ticket
        int day1 = costs[0] + minCost(i+1, currDay + 1, days, costs);
        int day7 = costs[1] + minCost(i+1, currDay + 7, days, costs);
        int day30 = costs[2] + minCost(i+1, currDay + 30, days, costs);

        return min(day1, min(day7, day30));

    }

public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        return minCost(0, 0, days, costs);
    }
};
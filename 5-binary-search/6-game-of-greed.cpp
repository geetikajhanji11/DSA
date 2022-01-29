/**************************************************************

GAME OF GREED

You are playing a game with your ‘k' friends. 
You have an array of N coins, at each index i you have a coin 
of value a[i].

Your task is to divide the coins, among a group of K friends 
by doing consecutive segments (k-subarrays) of the array.

Each friend will get a total sum of the coins in that subarray. 
Since all your friends are greedy, and they will pick the largest) 
k-1 segments and you will get the smallest segment. Find out the
maximum value you can make by making an optimal partition.

Note: The coins array may or may not be sorted!


Input:
    K = 3
    coins = {1, 2, 3, 4}

Output:
    3

Explanation:
    Ideal partition looks like this
    {1 + 2} = 3
    {3} = 3
    {4} = 4
    You will get max of 3 coins in best case

**************************************************************/

#include <iostream>
#include <string> 
#include <vector>
#include <cstring>
#include <math.h>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;

// checks if everyone is able to get coins with targeted sum 
// (i.e., able to form a partition of k subarrays)
bool canEveryoneGetCoins(vector<int> arr, int k, int targetSum) {
    int subarraySum = 0;
    for(int num : arr) {
        subarraySum += num;
        if(subarraySum >= targetSum) {
            k--;
            subarraySum = 0;
        }
    }
    if(k == 0) return true;
    else return false;
}

// return the max coins that you can win!
int getCoins(vector<int> arr, int k){

    int answer = INT_MIN;
    
    // low => least coin we can get
    // high => if k = 1, we get all coins, so high is sum of all coins
    int high = 0;
    int low = INT_MAX;
    for(int num : arr) {
        high += num;
        if(num < low) {
            low = num;
        }
    }

    // binary search
    while(low <= high) {
        
        // mid is the least number of coins
        // everyonce can get, i.e., i have
        // mid coins, everyone else can have
        // >= mid coins
        int mid = (low + high) / 2;

        // if k-subarrays can be made for least sum = mid,
        // then maximize the mid by going to right
        if(canEveryoneGetCoins(arr, k, mid)) {
            answer = mid;
            low = mid + 1;
        } 
        
        // everyone cannot get coins, so go to left
        else {
            high = mid - 1;
        }


    } 
    return answer;
    
}

// main function
int main() {

    vector<int> coins{1, 2, 3, 4};
    int k = 3;
    
    cout<<getCoins(coins, k);

}
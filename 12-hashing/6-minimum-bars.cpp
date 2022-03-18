/******************************************************************************

QUICK BROWN FOX

Given a string without spaces, and a list of words. Write a function that
finds the minimum bars to be added to the string so that all the resulting
words in are found in the list.

Input: 
    string = "thequickbrownfoxjumpsoverthehighbridge"
    words = {
        "the",
        "fox",
        "thequickbrownfox",
        "jumps",
        "lazy",
        "lazyfox",
        "highbridge",
        "the",
        "over",
        "bridge",
        "high",
        "tall",
        "quick",
        "brown"
    }
Output: 
    4
    
Explanation:
    thequickbrownfox|jumps|over|the|highbridge
    
*******************************************************************************/
#include<iostream>
#include<map>
#include<unordered_set>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;


int minimumBarsHelper(string s, vector<int> &dp, int index, unordered_set<string> &wordsSet) {
    
    // base case
    if(index == s.length()) {
        return 0;
    }
    
    if(dp[index] != -1) return dp[index];
    
    // rec case
    int ans = INT_MAX;
    string currString = "";
    
    for(int i=index; i<s.length(); i++) {
        currString += s[i];
        
        if(wordsSet.find(currString) != wordsSet.end()) {
            int remainingAns = minimumBarsHelper(s, dp, i+1, wordsSet);
            if(remainingAns != -1) {
                ans = min(ans, 1 + remainingAns);
            }
        } 
    }
    
    if(ans == INT_MAX) return -1;
    
    return ans;
}



int minimumBars(string s, vector<string> words) {
    unordered_set<string> wordsSet;
    for(string word : words) {
        wordsSet.insert(word);
    }
    
    vector<int> dp(s.length(), -1);
    
    int bars = minimumBarsHelper(s, dp, 0, wordsSet);
    
    return bars - 1;
}

int main() {
    
    // string s = "thequickbrownfoxjumpsoverthehighbridge";
    // vector<string> words{
    //     "the",
    //     "fox",
    //     "thequickbrownfox",
    //     "jumps",
    //     "lazy",
    //     "lazyfox",
    //     "highbridge",
    //     "the",
    //     "over",
    //     "bridge",
    //     "high",
    //     "tall",
    //     "quick",
    //     "brown"
    // };
    string s = "codingminutes";
    vector<string> words{
        "coding",
        "minute",
        "hours",
        "s",
        "code",
        "cod",
        "ing"
    };
    
    int result = minimumBars(s, words);
    cout<<"\nNumber of minimumBars: "<<result;
    
    return 0;
}

/*******************************************************************
Optimization: If the target can be spelled out by a group of stickers, 
at least one of them has to contain character target[0]. 

So I explicitly require next sticker containing target[0], 
which significantly reduced the search space.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Solution {
public:

    int minStickers(string target, vector<vector<int>>& stickersMaps, unordered_map<string, int>& dp) {

        // precomputed
        if (dp.count(target)) return dp[target];

        // making a map of "target" string
        vector<int> targetMap(26, 0);
        for (char ch : target) {
            targetMap[ch-'a']++;
        }

        // check for every sticker
        int ans = INT_MAX;
        for (int i = 0; i<stickersMaps.size(); i++) {

            // optimization
            if (stickersMaps[i][target[0]-'a'] == 0) continue; 

            // apply a sticker on every character a-z
            string s = "";
            for (int j=0; j<26; j++) {
                if (targetMap[j] - stickersMaps[i][j] > 0) {
                    // leftover count of character AND character in target
                    int countCh = targetMap[j] - stickersMaps[i][j]; 
                    char ch = 'a' + j;
                    s += string(countCh, ch);
                }
            }
                
            int remainingMinStickers = minStickers(s, stickersMaps, dp);
            if (remainingMinStickers != -1) {
                ans = min(ans, 1 + remainingMinStickers);
            }
        }

        return dp[target] = (ans == INT_MAX) ? -1 : ans;
    }

    int minStickers(vector<string>& stickers, string target) {

        int m = stickers.size();
        vector<vector<int>> stickersMaps(m, vector<int>(26, 0));

        // count characters a-z for each sticker 
        for (int i=0; i<m; i++) {
            auto sticker = stickers[i];
            for (char ch : sticker) {
                stickersMaps[i][ch-'a']++;
            }
        }
            
        unordered_map<string, int> dp;
        dp[""] = 0;
        return minStickers(target, stickersMaps, dp);
    }
    
};

// *********** DOES NOT WORK ON LEETCODE, BUT LOGIC IS CORRECT ***********
int minStickersDP(vector<vector<int>> stickersMaps, vector<int> targetMap, int ctr, map<vector<int>, int> &dp) {

    // if all unique characters have been 
    // matched, (target empty) return 0
    if(ctr == 0) return 0;

    // precomputed
    if(dp.find(targetMap) != dp.end()) return dp[targetMap];

    int ans = INT_MAX;

    vector<int> tempTargetMap = targetMap;
    int tempCtr = ctr;

    for(int j=stickersMaps.size()-1; j>=0; j--) {

        vector<int> stickerMap = stickersMaps[j];
        bool madeChanges = false;

        // for each character, if both targetMap and stickerMap
        // have count of character > 0, make change 
        for(int i=0; i<26; i++) {
            if(targetMap[i] > 0 && stickerMap[i] > 0) {
                madeChanges = true;
                targetMap[i] -= stickerMap[i];
                if(targetMap[i] <= 0) {
                    targetMap[i] = 0;
                    ctr--;
                }
            }
        }

        // if we found that this current sticker
        // contained potential characters of target
        // only then, make a recursive call
        if(madeChanges) {
            int remaining = minStickersDP(stickersMaps, targetMap, ctr, dp);
            if(remaining == INT_MAX) {
                // backtracking
                ctr = tempCtr;
                targetMap = tempTargetMap;
                continue;
            }
            ans = min(ans, 1 + remaining);
        } else {
            stickersMaps.pop_back();
        }

        // backtracking
        ctr = tempCtr;
        targetMap = tempTargetMap;
    }

    return dp[targetMap] = ans;
}

int minStickers(vector<string>& stickers, string target) {

    int MAX = 26;

    // make map of "target"
    vector<int> targetMap(MAX, 0);
    for(char ch : target) {
        targetMap[ch-'a']++;
    }

    // count total unique characters 
    // in the word "target"
    int ctr = 0;
    for(int cnt : targetMap) {
        if(cnt > 0) ctr++;
    }

    // make map of each "sticker"
    // and push each in vector
    vector<vector<int>> stickersMaps;
    for(string sticker : stickers) {
        vector<int> charCount(MAX, 0);
        int charactersMatched = 0;
        for(char ch : sticker) {
            charCount[ch-'a']++;
            if(targetMap[ch-'a'] > 0) {
                charactersMatched++;
            }
        }

        // don't include stickers in which none of the 
        // characters match the characters in target 
        if(charactersMatched == 0) continue;

        stickersMaps.push_back(charCount);
    }   


    map<vector<int>, int> dp; 
    int ans = minStickersDP(stickersMaps, targetMap, ctr, dp);

    return ans == INT_MAX ? -1 : ans;
}


// ***************** ALSO WORKED, BUT BAD TIME COMPLEXITY ************************* 
// int minStickersDP(vector<vector<int>> &stickersMaps, vector<int> targetMap, int ctr, map<vector<int>, int> &dp) {

//     // if all unique characters have been 
//     // matched, (target empty) return 0
//     if(ctr == 0) return 0;

//     // precomputed
//     if(dp.find(targetMap) != dp.end()) return dp[targetMap];

//     int ans = INT_MAX;

//     vector<int> tempTargetMap = targetMap;
//     int tempCtr = ctr;

//     for(auto stickerMap : stickersMaps) {

//         bool madeChanges = false;

//         // for each character, if both targetMap and stickerMap
//         // have count of character > 0, make change 
//         for(int i=0; i<26; i++) {
//             if(targetMap[i] > 0 && stickerMap[i] > 0) {
//                 madeChanges = true;
//                 targetMap[i] -= stickerMap[i];
//                 if(targetMap[i] <= 0) {
//                     targetMap[i] = 0;
//                     ctr--;
//                 }
//             }
//         }

//         // if we found that this current sticker
//         // contained potential characters of target
//         // only then, make a recursive call
//         if(madeChanges) {
//             int remaining = minStickersDP(stickersMaps, targetMap, ctr, dp);
//             if(remaining == INT_MAX) continue;
//             ans = min(ans, 1 + remaining);
//         }

//         // backtracking
//         ctr = tempCtr;
//         targetMap = tempTargetMap;
//     }

//     return dp[targetMap] = ans;
// }

// int minStickers(vector<string>& stickers, string target) {

//     int MAX = 26;

//     // make map of "target"
//     vector<int> targetMap(MAX, 0);
//     for(char ch : target) {
//         targetMap[ch-'a']++;
//     }

//     // count total unique characters 
//     // in the word "target"
//     int ctr = 0;
//     for(int cnt : targetMap) {
//         if(cnt > 0) ctr++;
//     }

//     // make map of each "sticker"
//     // and push each in vector
//     vector<vector<int>> stickersMaps;
//     for(string sticker : stickers) {
//         vector<int> charCount(MAX, 0);
//         int charactersMatched = 0;
//         for(char ch : sticker) {
//             charCount[ch-'a']++;
//             if(targetMap[ch-'a'] > 0) {
//                 charactersMatched++;
//             }
//         }

//         // don't include stickers in which none of the 
//         // characters match the characters in target 
//         if(charactersMatched == 0) continue;

//         stickersMaps.push_back(charCount);
//     }   


//     map<vector<int>, int> dp; 
//     int ans = minStickersDP(stickersMaps, targetMap, ctr, dp);

//     return ans == INT_MAX ? -1 : ans;
// }


int main() {

    return 0;
}
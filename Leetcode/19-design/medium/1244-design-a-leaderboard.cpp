/*******************************************************************
QUICKSORT SOLUTION

Maintain two lists that store players and scores respectively, 
and maintain size that represents the number of players that have 
score greater than 0. At any time, the elements in the scores list 
are sorted in descending order. For index i such that 0 <= i < size, 
the element at index i in the players list is the id of the player 
that ranks i-th, and the element at index i in the scores list is 
the player’s score.

For the constructor, 
    initialize the two lists and initialize size to 0.

For addScore(playerId, score), 
    if size == 0, then simply add playerId and score to the lists. 
    Otherwise, if playerId is in the players list, then calculate the 
    player’s new score, remove the previous player id and the previous 
    score from both lists, use binary search to find the insertion 
    index of the new score, and add playerId and score at the insertion 
    index in the lists. If playerId is not in the players list, then 
    use binary search to find the insertion index of score, and add 
    playerId and score at the insertion index in the lists.

For top(K), 
    calculate the sum of the first K elements of the scores list, 
    and return. If K > size, then calculate the sum of all the 
    elements of the scores list, and return.

For reset(playerId), 
    find the index index of playerId in the players list, 
    and remove the elements at index index from both lists.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ********* HEAP SOLUTION *********
class Leaderboard { 

    unordered_map<int, int> scoreOfPlayer;

public:

    // Update the leaderboard by adding score to the given player's score. 
    // If there is no player with such id in the leaderboard, 
    // add him to the leaderboard with the given score.
    // O(1)
    void addScore(int playerId, int score) {
        if(scoreOfPlayer.find(playerId) != scoreOfPlayer.end()) {
            scoreOfPlayer[playerId] += score;
        } else {
            scoreOfPlayer.insert({playerId, score});
        }
    }

    // Return the score sum of the top K players.
    // O(klogn)
    int top(int k) {

        k = min(k, (int)scoreOfPlayer.size());

        priority_queue<int, vector<int>, greater<int>> minHeap;

        int sum = 0;
        for(auto kv : scoreOfPlayer) {
            int score = kv.second;
            minHeap.push(score);
            sum += score;

            if(minHeap.size() > k) {
                int top = minHeap.top(); minHeap.pop();
                sum -= top;
            } 
        }

        return sum;
    }

    // Reset the score of the player with the given id to 0. 
    // It is guaranteed that the player was added to the leaderboard 
    // before calling this function.
    // O(1)
    void reset(int playerId) {
        scoreOfPlayer.erase(playerId);
    }


};

// ********* QUICK SORT SOLUTION *********

// class Leaderboard {
//     List<Integer> playerIDs;
//     List<Integer> scores;
//     int size;

//     public Leaderboard() {
//         playerIDs = new ArrayList<Integer>();
//         scores = new ArrayList<Integer>();
//         size = 0;
//     }
    
//     public void addScore(int playerId, int score) {
//         if (size == 0) {
//             playerIDs.add(playerId);
//             scores.add(score);
//         } else {
//             int idIndex = playerIDs.indexOf(playerId);
//             if (idIndex >= 0) {
//                 int newScore = scores.get(idIndex) + score;
//                 playerIDs.remove(idIndex);
//                 scores.remove(idIndex);
//                 int index = binarySearch(scores, newScore);
//                 if (index < 0)
//                     index = -index - 1;
//                 playerIDs.add(index, playerId);
//                 scores.add(index, newScore);
//             } else {
//                 int index = binarySearch(scores, score);
//                 if (index < 0)
//                     index = -index - 1;
//                 playerIDs.add(index, playerId);
//                 scores.add(index, score);
//             }
//         }
//         size++;
//     }
    
//     public int top(int K) {
//         K = Math.min(K, size);
//         int sum = 0;
//         for (int i = 0; i < K; i++)
//             sum += scores.get(i);
//         return sum;
//     }
    
//     public void reset(int playerId) {
//         int index = playerIDs.indexOf(playerId);
//         playerIDs.remove(index);
//         scores.remove(index);
//         size--;
//     }

//     public int binarySearch(List<Integer> list, int key) {
//         int size = list.size();
//         int low = 0, high = size - 1;
//         while (low <= high) {
//             int mid = (high - low) / 2 + low;
//             int num = list.get(mid);
//             if (num == key)
//                 return mid;
//             else if (num > key)
//                 low = mid + 1;
//             else
//                 high = mid - 1;
//         }
//         return -low - 1;
//     }
// }

int main() {

    return 0;
}
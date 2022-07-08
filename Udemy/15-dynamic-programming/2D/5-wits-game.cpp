/*******************************************************************
 * GAME OF WITS
 * 
 * Oswald and Henry are playing a game with alternating turns.
 * Oswald plays first. The game starts with all the game cards 
 * arranged in a single row. The cards are of two types 'O' and 
 * 'H'. During Oswald's turn, he must choose and remove an 'O'
 * card that is either the leftmost or the rightmost card 
 * remaining. During Henry's turn he must choose and remove an 
 * 'H' card that is either the leftmost or the rightmost card 
 * remaining. If at any point one of the players do not have a
 * legal move (possibly because there are no cards remaining)
 * that player loses the game, and the other player is awarded 
 * 1 point plus 1 additional point for each card that remains 
 * on the board.
 * 
 * Each player plays optimally to win and to maximize their
 * own score. A player that cannot guarantee a win plays to
 * minimize the opponent's score. Given the starting board,
 * can you find out who wins and what is their score?
 * 
 * Input:
 *      1. s = "OHOHHHOO"
 *      2. s = "HOOOOHHO"
 * Ouput:
 *      1. O, 6
 *      2. H, 7
 *  
 * Explanation:
 *      On his first turn, Oswald can choose to remove either 
 *      the leftmost or the rightmost cards, as both are 'O'.
 *      Suppose he chooses the leftmost (smart move). Then, 
 *      the board would become "HOHHHOO". Then, Henry would have 
 *      no choice but to remove the new leftmost card as the 
 *      rightmost card is not 'H'. leaving "OHHOO". Oswald can
 *      choose again, and this time he chooses the rightmost card,
 *      leaving "OHHHO" for Henry's turn. At this point, Henry
 *      has no valid move. So, Oswald won. Since there are 5 
 *      pieces remaining, Oswald wins 1 + 5 = 6 points.
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int game(int i, int j, string s, vector<vector<int>> &dp) {

    if(i + 1 == j) {
        if(s[i] == 'O' && s[j] == 'O') return 2;
        else if(s[i] == 'H' && s[j] == 'H') return -3;
        else return -1;
    }

    if(i == j) {
        if(s[i] == 'O') return 1;
        else return -2;
    }

    if(dp[i][j] != 0) return dp[i][j];

    // H---------H
    if(s[i]=='H' && s[j]=='H'){
        return dp[i][j] = -1 * (j - i + 1) - 1;
    }

    // H---------O
    else if(s[i] == 'H' && s[j] == 'O') {
        int op1 = INT_MAX;
        if(s[j-1] == 'H') {
            op1 = game(i, j-2, s, dp);
        }
        int op2 = game(i+1, j-1, s, dp);
        return dp[i][j] = min(op1, op2);
    }

    // O---------H
    else if(s[i] == 'O' && s[j] == 'H') {
        int op1 = INT_MAX;
        if(s[i+1] == 'H') {
            op1 = game(i+2, j, s, dp);
        }
        int op2 = game(i+1, j-1, s, dp);
        return dp[i][j] =  min(op1, op2);
    }

    // O---------O
    else {
        if(s[i+1] == 'O') return j - i + 1;
        else if(s[j-1] == 'O') return j - i + 1;
        else {
            int op1 = game(i+2, j, s, dp);
            int op2 = game(i, j-2, s, dp);
            return dp[i][j] =  max(op1, op2);
        }
    }
    
}

pair<char,int> GameOfWits(string s) {

    int n = s.length();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    int score = game(0, n-1, s, dp);

    if(score > 0) return {'O', abs(score)};
    else return {'H', abs(score)};
}

int main() {

    string s = "HOOOOHHO";
    auto p = GameOfWits(s);
    cout<<p.first<<": "<<p.second;

    return 0;
}
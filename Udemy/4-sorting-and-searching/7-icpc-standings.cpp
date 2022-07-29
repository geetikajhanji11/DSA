/**************************************************************

ICPC STANDINGS

Usually, results of competitions are based on the scores of participants. 
However, we are planning a change for the next year of ICPC. 
During the registration each team will be able to enter a single 
positive integer : their preferred place in the ranklist. 
We would take all these preferences into account, and at the end 
of the competition we will simply announce a ranklist
that would please all of you.

But wait... How would that ranklist look like if it won't be possible 
to satisfy all the requests?

Suppose that we already have a ranklist. 
For each team, compute the distance between their preferred place 
and their place in the ranklist. The sum of these distances will 
be called the badness of this ranklist.

Given team names and their preferred placements find one ranklist 
with the minimal possible badness.

Input:
The input is stored in a vector<pair<string,int>> 
where the each pair stores the team name & its preferred rank.

    WinOrBooze 1
    BallofDuty 2
    Whoknows 2
    BholeChature 1
    DCECoders 5
    StrangeCase 7
    Whoknows 7

Output: 
    5

Explanation:
    A possible rank list can be like this, 
    which has a total badness of 5.
    
    1. WinorBooze
    2. Ballofouty
    3. Whoknows
    4, BholeChature
    5. DCECoders
    6. Whoknows
    7. StrangeCase

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

int badness(vector<pair<string,int> > teams){
    
    int sum = 0;

    // considering 1 based index
    vector<int> count(teams.size() + 1, 0);
    for(auto team : teams) {
        count[team.second]++;
    }

    int pos = 1;
    for(int i=1; i<=teams.size(); i++)  {
        // as long as number of teams
        // in ith position are not 0
        while(count[i] != 0) {
            sum += abs(pos - i);
            pos++;
            count[i]--;
        }
    }       

    
    return sum;
}

// main function
int main() {

    vector<pair<string, int>> teams{
        {"WinOrBooze", 1},
        {"BallofDuty", 2},
        {"Whoknows", 2},
        {"BholeChature", 1},
        {"DCECoders", 5},
        {"StrangeCase", 7},
        {"Whoknows", 7}
    };

    int answer = badness(teams);
    cout<<"\nBadness = "<<answer;
    
    return 0;

}
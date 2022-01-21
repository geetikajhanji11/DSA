#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;


bool my_compare(pair<int,int> a, pair<int,int> b) {
    return a.second < b.second;
}

int countActivites(vector<pair<int,int> > activities) {

    // sorting the activities according to finish time
    sort(activities.begin(), activities.end(), my_compare);

    int count = 1;
    int finish = activities[0].second;

    for(int i=1; i<activities.size(); i++) {
        if(activities[i].first >= finish) {
            count++;
            finish = activities[i].second;
        }
    }

    return count;
        
}

// main function
int main() {

    vector<pair<int, int>> activities {
        {7, 9},
        {0, 10},
        {4, 5},
        {8, 9},
        {4, 10},
        {5, 7}
    };

    int result = countActivites(activities);
    cout<<"\nMax activities = "<<result;

    return 0;
}





/*

#include <iostream>
#include <string> 
#include <vector>
#include <sstream>
#include <cstring>
#include <math.h>
#include<algorithm>
#include<climits>
#include<unordered_map>
using namespace std;

// descending
bool my_compare(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) 
        return a.second > b.second;
    return a.first > b.first;
}

int countActivites(vector<pair<int,int> > activities) {
    
    int result = 0;

    // sorting the activities according to start time
    sort(activities.begin(), activities.end(), my_compare);

    // printing activities
    // for(auto p : activities) {
    //     cout<<p.first<<" -> "<<p.second<<endl;
    // }

    // creating map
    unordered_map<int, int> mp;
    for(auto p : activities) {
        int count = 1;
        if(mp.find(p.second) != mp.end()) {
            count += mp.find(p.second)->second;
            mp[p.first] = count;
        } else {
            mp[p.first] = count;
        }
        result = max(result, count);
    }

    // display map
    // for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    //     cout << itr->first<< '\t' << itr->second << '\n';
    // }
    
    return result;
    
    
}

// main function
int main() {

    vector<pair<int, int>> activities {
        {7, 9},
        {0, 10},
        {4, 5},
        {8, 9},
        {4, 10},
        {5, 7}
    };

    int result = countActivites(activities);
    cout<<"\nMax activities = "<<result;

    return 0;
}



*/
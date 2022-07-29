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

/*

ASSIGNMENT:

1. Find smallest window that contains the reqd sum
(compute difference of indexes ood the result vector
and return the pair having least difference)

2. handle if you have negative integers in the arrays

*/

// ------- more readable -----------
vector<pair<int, int>> getPlotPairs(vector<int> plots, int k) {

    int left = 0;
    int right = 0;

    int curr_sum = 0;
    int target = k;

    vector<pair<int,int>> result;

    while(right < plots.size()) {
        curr_sum += plots[right];

        while(curr_sum > target) {
            curr_sum -= plots[left];
            left++;
        }
        
        if(curr_sum == target) {
            result.push_back({left, right});
        }   

        right++;
    }

    return result;
}

vector<pair<int, int>> getPlotPairs(vector<int> plots, int k) {
    vector<pair<int, int>> result;

    int sum = plots[0];
    int left = 0;
    int right = 0;

    cout<<"Current sum = "<<sum<<" at "<<left<<", "<<right<<endl;

    while(right < plots.size()) {

        if(sum < k) {
            right++;
            sum += plots[right];
            cout<<"Adding "<<plots[right]<<", sum = "<<sum<<endl;
        } else if(sum > k) {
            sum -= plots[left];
            left++;
            cout<<"Removing "<<plots[left]<<", sum = "<<sum<<endl;
        } else {
            cout<<"FOUND => sum = "<<sum<<endl;
            result.push_back({left, right});
            right++;
            sum += plots[right];
        }
    }



    return result;
}



// main function
int main() {

    vector<int> plots{1, 3, 2, 1, 4, 1, 3, 2, 1, 1, 2};
    int k = 8;

    auto result = getPlotPairs(plots, k);

    cout<<"\nPlot Pairs\n";
    for(auto p : result) {
        cout<<p.first<<", "<<p.second<<endl;
    }


    return 0;
}


/* ANOTHER SOLUTION

vector<pair<int, int>> getPlotPairs(vector<int> plots, int k) {
    vector<pair<int, int>> result;

    int sum = plots[0];
    int left = 0;
    int right = 0;

    while(left != plots.size() && right != plots.size()) {

        int leftSum = sum - plots[left];
        int rightSum = sum + plots[right];

        int leftDiff = abs(k - leftSum);
        int rightDiff = abs(k - rightSum);

        if(leftDiff < rightDiff) {
            sum -= plots[left];
            left++;
            if(left == plots.size()) continue;
        } else {
            right++;
            if(right == plots.size()) continue;
            sum += plots[right];
        }

        if(sum == k) {
            result.push_back({left, right});
        }
    }

    return result;
}

*/
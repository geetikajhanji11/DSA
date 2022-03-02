/**************************************************************

SIMPLIFY PATH



**************************************************************/
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<unordered_map>
#include<algorithm>
using namespace std;

vector<int> stockSpan(vector<int> v) {

    stack<int> s;
    vector<int> span(v.size(), 0);
    span[0] = 1;
    s.push(0);

    // stack should be in decreasing order
    // small
    // .....
    // large
    for(int i=1; i<v.size(); i++) {
        
        while(!s.empty() && v[s.top()] <= v[i]) {
            s.pop();
        }
        
        if(!s.empty()) {
            span[i] = i - s.top();
        } else {
            span[i] = i + 1;
        }

        s.push(i);

    }
    return span;
    
}

int main() {

    vector<int> v = {100, 80, 60, 70, 60, 75, 85};
    vector<int> span = stockSpan(v);

    for(int num : span) {
        cout<<num<<" ";
    }

	return 0;
}
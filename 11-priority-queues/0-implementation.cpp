/******************************************************************************

HEAP IMPLEMENTATION

*******************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Compare {
public:
    bool operator()(int a, int b) {
        return a > b;
    }
};

int main() {

    vector<int> arr{10, 15, 20, 13, 6, 90};
    int n = arr.size();
    
    priority_queue<int, vector<int>, Compare > heap;
    
    for(int num : arr) {
        heap.push(num);
    }
    
    while(!heap.empty()) {
        cout<<heap.top()<<endl;
        heap.pop();
    }

    return 0;
}

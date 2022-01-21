#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Complete this method, don't write main
vector<string> fizzbuzz(int n){

    vector<string> result;
    for(int i=1; i<=n; i++) {
        string s;
        if(i % 15 == 0) {
            s = "FizzBuzz";
        } else if(i % 3 == 0) {
            s = "Fizz";
        } else if(i % 5 == 0) {
            s = "Buzz";
        } else {
            s = to_string(i);
        }
        result.push_back(s);
    }
    
    return result;
}

int main() {

    vector<string> result = fizzbuzz(15);
    for(string s : result) {
        cout<<s<<endl;
    }

    return 0;
}

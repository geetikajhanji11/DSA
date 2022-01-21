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

You are given a vector of numbers. You want 
to concatenate these numbers together to form
the lexicographically largest number. Print
that largest number. You can't reaarange the
digits of any number. However, you can place 
the numbers next to each other in any order 

*/

bool my_compare(string a, string b) {
    return a + b > b + a;
}

string concatenate(vector<int> numbers){
    //complete this method and return the largest number you can form as a string

    vector<string> strNums;
    for(int num : numbers) {
        strNums.push_back(to_string(num));
    }

    sort(strNums.begin(), strNums.end(), my_compare);

    string result = "";
    for(string str : strNums) {
        cout<<str<<endl;
        result += str;
    }

    
    return result;
}

// main function
int main() {

    vector<int> numbers{10, 11, 20, 30, 3};

    string result = concatenate(numbers);
    cout<<"\nResult = "<<result;

    return 0;
}


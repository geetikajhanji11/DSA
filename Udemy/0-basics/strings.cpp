#include<iostream>
#include <string> 
#include<vector>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};

    int index = big.find(small);

    while(index != -1) {
        result.push_back(index);
        index = big.find(small, index + 1);
    }

    return result;
}

int main() {

    
    string s; // dynamic array
    cout<<"Enter s = ";
    getline(cin, s);
    cout<<"s = "<<s<<endl;

    // input string with delimiter
    string s_with_delimiter;
    cout<<"\nEnter s with . = ";
    getline(cin, s_with_delimiter, '.');
    cout<<"s_with_delimiter = "<<s_with_delimiter;
    

    // find function
    string s1 = "My name is geetika is";

    int index0 = s1.find("is");
    if(index0 == -1) {
        cout<<"not found";
    } else {
        cout<<"\nindex = "<<index0;
    }

    int index1 = s1.find("is", index0 + 1);
    if(index1 == -1) {
        cout<<"not found";
    } else {
        cout<<"\nindex = "<<index1;
    }

    // finding all occurences of a 
    // substring in a string
    string big = "I liked the movie, acting in movie was great!";
    string small = "movie";
    vector<int> result = stringSearch(big, small);
    for(int index : result) {
        cout<<index<<endl;
    }
    

    return 0;
}


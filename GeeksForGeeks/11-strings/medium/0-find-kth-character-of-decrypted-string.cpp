/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<string, int> getStringAndCount(string &decrypted, int &i) {
    int n = decrypted.length();
    
    string s;
    while(i < n && isalpha(decrypted[i])) {
        s.push_back(decrypted[i]);
        i++;
    }

    string count_str = "";
    while(i < n && isdigit(decrypted[i])) {
        count_str.push_back(decrypted[i]);
        i++;
    }
    i--;

    int count = stoi(count_str);
    return {s, count};
}

char kth_character(string decrypted, int k) {

    for(int i=0; i<decrypted.length(); i++) {

        pair<string, int> p = getStringAndCount(decrypted, i);
        string word = p.first;
        int count = p.second * word.length();

        if(count < k) {
            k -= count;
        } 
        
        else {
            k--;
            int index = 0;
            while(k != 0) {
                index++;
                if(index == word.length()) index = 0;
                k--;
            }
            return word[index];
        }
    }

    return '-';
}
 
int main() {

    string s = "a2b2c3";
    int k = 5;
    cout<<kth_character(s, k)<<endl;

    s = "ab4c2ed3";
    k = 9;
    cout<<kth_character(s, k)<<endl;

    s = "ab4c12ed3";
    k = 21;
    cout<<kth_character(s, k)<<endl;

    s = "ab4cdef10";
    k = 22;
    cout<<kth_character(s, k)<<endl;

    return 0;
}
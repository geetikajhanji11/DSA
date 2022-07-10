/*******************************************************************

*******************************************************************/
#include<bits/stdc++.h>
using namespace std;

int get_max_frequency(unordered_map<char, int> m) {
    int answer = 0;
    for(auto it=m.begin(); it!=m.end(); it++) {
        answer = max(answer, it->second);
    }
    return answer;
}

int characterReplacement(string s, int k) {
    int n = s.length();
    if(n == 0) return 0;

    unordered_map<char, int> m;
    int left = 0;
    int right = 0;

    int answer = 0;

    m[s[right]]++; // for first character

    while(right < n) {
        int max_frequency = get_max_frequency(m);
        int curr_length = right - left + 1;

        int replaceable = curr_length - max_frequency;

        if(replaceable <= k) {
            answer = max(answer, curr_length);
            right++;
            if(right >= n) break; // index out of bounds check
            m[s[right]]++;
        } 
        
        else {
            m[s[left]]--;
            left++;
        }
        
    }

    return answer;
}

int main() {

    cout<<characterReplacement("AABABBA", 1);
    return 0;
}
/*******************************************************************
Partition string so each letter appears in at most 1 part, return sizes
Ex. s = "ababcbacadefegdehijhklij" -> [9,7,8]

Greedy: determine last occurrence of each char, then loop thru & get sizes

Time: O(n)
Space: O(1)
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// vector<int> partitionLabels(string s) {
//     map<char, pair<int, int>> m;
//     for(int i=0; i<s.length(); i++) {
//         char ch = s[i];
//         if(m.find(ch) == m.end()) {
//             m[ch] = {i, i};
//             continue;
//         }
//         m[ch] = {m[ch].first, i};
//     }

//     set<pair<int,int>> set_of_pairs;
//     for(auto it=m.begin(); it!=m.end(); it++) {
//         // cout<<it->first<<": "<<it->second.first<<", "<<it->second.second<<endl;
//         set_of_pairs.insert({it->second.first, it->second.second});
//     }

//     vector<int> result;

//     pair<int, int> interval = *set_of_pairs.begin();
//     for(auto it=set_of_pairs.begin(); it!=set_of_pairs.end(); it++) {
        
//         int first = (*it).first;
//         int second = (*it).second;

//         if(interval.first <= first && first <= interval.second) {
//             interval.second = max(interval.second, second);
//         } else {
//             result.push_back(interval.second - interval.first + 1);
//             interval = *it;
//         }
//     }

//     result.push_back(interval.second - interval.first + 1);
//     return result;
// }


vector<int> partitionLabels(string s) {
    unordered_map<char, int> last_occurrence;
    for(int i=0; i<s.length(); i++) {
        last_occurrence[s[i]] = i;
    }

    int size = 0;
    int end = 0;

    vector<int> result;
    for(int i=0; i<s.length(); i++) {

        size++;

        char ch = s[i];
        if(last_occurrence[ch] > end) {
            end = last_occurrence[ch];
        }

        if(i == end) {
            result.push_back(size);
            size = 0;
        }
        
    }

    return result;
}

int main() {

    string s = "ababcbacadefegdehijhklij";
    auto res = partitionLabels(s);
    cout<<"\n\nres: ";
    for(int num : res) cout<<num<<" ";
    return 0;
}
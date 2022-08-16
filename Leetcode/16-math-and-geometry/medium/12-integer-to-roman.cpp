/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// ************** SHORT AND CONCISE **************
string intToRoman(int num) {
    
    vector<string> symbol = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    
    string result = "";
    for(int i=0; num != 0; i++) {
        while(num >= value[i]) {
            num -= value[i];
            result += symbol[i];
        }
    }
    
    return result;
}

// ************** COMPLICATED **************
class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int, char> ItoR;
        ItoR[1] = 'I';
        ItoR[5] = 'V';        
        ItoR[10] = 'X';
        ItoR[50] = 'L';
        ItoR[100] = 'C';
        ItoR[500] = 'D';
        ItoR[1000] = 'M';
        vector<int> keys = {1,5,10,50,100,500,1000};

        string result = "";
        int n = 0; // for power of 10
        
        while(num != 0) {
            int target = (num % 10) * pow(10, n);
            num = num / 10;
            n++;

            if(target == 0) continue;

            // find roman numeral for target
            // insert in reverse order
            
            // find a key that is <= target
            int key;
            int i = 0;
            for(i=0; i<keys.size(); i++) {
                if(keys[i] <= target) {
                    key = keys[i];
                }
                else {
                    i--;
                    break;
                }
            }
            
            if(ItoR.find(target) != ItoR.end()) {
                result += ItoR[target];
                continue;
            }
            
            
            // check for 4 
            if(i+1 < keys.size() && keys[i+1] - keys[i] == target) {
                string curr = "";
                curr += ItoR[keys[i]];
                curr += ItoR[keys[i+1]];
                reverse(curr.begin(), curr.end());
                result += curr;
                continue;
            }
            
            // check for 9
            if(i+1 < keys.size() && i-1 >= 0 && keys[i+1] - keys[i-1] == target) {
                string curr = "";
                curr += ItoR[keys[i-1]];
                curr += ItoR[keys[i+1]];
                reverse(curr.begin(), curr.end());
                result += curr;
                continue;
            }
            
            // keep adding key until target < key
            string curr = "";
            while(target >= key) {
                curr += ItoR[key];
                target -= key;
            }
            
            // calculate for the rest of the target
            int rest = target;
            
            // add previous keys
            if(i-1 >= 0) {
                int prevKey = keys[i-1]; 
                while(rest != 0) {
                    curr += ItoR[prevKey];
                    rest -= prevKey;
                }
            } 
            
            // for "1"
            while(rest != 0 && i == 0) {
                curr += ItoR[key];
                rest -= key;
            }
            
            reverse(curr.begin(), curr.end());
            result += curr;
            
        }

        // reverse string
        reverse(result.begin(), result.end());

        return result;
    }
};
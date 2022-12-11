/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int i = 0; // version1
        int j = 0; // version2

        while(i < version1.length() || j < version2.length()) {

            string str1 = "";
            string str2 = "";

            while(i < version1.length() && version1[i] != '.') {
                str1 += version1[i];
                i++;
            }

            while(j < version2.length() && version2[j] != '.') {
                str2 += version2[j];
                j++;
            }

            int revision1 = str1.length() == 0 ? 0 : stoi(str1);
            int revision2 = str2.length() == 0 ? 0 : stoi(str2);

            i++; // to skip '.'
            j++; // to skip '.'

            if(revision1 == revision2) continue;
            else if(revision1 < revision2) return -1;
            else return 1;
        }

        // both versions are same
        return 0;
    }
};
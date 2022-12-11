/*******************************************************************
https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/discuss/1375390/Python-Solution-with-detailed-explanation-and-proof-and-common-failure-analysis
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {

        long long totalProjects = accumulate(milestones.begin(), milestones.end(), 0LL);
        
        long long maxProject = *max_element(milestones.begin(), milestones.end());
        long long restProjects = totalProjects - maxProject;

        if(restProjects >= maxProject) {
            return totalProjects;
        }

        return (2 * restProjects) + 1;
    }
};
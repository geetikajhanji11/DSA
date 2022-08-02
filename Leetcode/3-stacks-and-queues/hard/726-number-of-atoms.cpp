/*******************************************************************
NOT COMPLETE YET
have to check for cases where  AS(HJ(HG8)2(FG)3)3
*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

pair<string, long long int> getAtomAndCount(string formula, long long int &i) {
    long long int n = formula.length();
    string atom = "";
    string count_string = "";
    long long int count = 0;
    if(isupper(formula[i])) {
        atom += formula[i];
        long long int j = i + 1;
        if(j < n && islower(formula[j])) {
            atom += formula[j];
            j++;
        }
        while(isdigit(formula[j])) {
            count_string += formula[j];
            j++;
        }
        if(count_string.length() == 0) count_string = "1";
        count = stoll(count_string);
        i = j - 1;
    }

    return {atom, count};
}

string countOfAtoms(string formula) {

    stack<pair<string, long long int>> s;
    map<string, long long int> final_map;
    long long int n = formula.length();

    for(long long int i=0; i<n; i++) {

        // start of stack
        if(formula[i] == '(') {
            s.push({"(", -1});
        } 
        
        // resolve the current formula in parentheses
        else if(formula[i] == ')') {
            i++;
            string multiplier_string = "";
            while(i < n && isdigit(formula[i])) {
                multiplier_string += formula[i];
                i++;
            }
            i = i - 1;

            if(multiplier_string.length() == 0) {
                multiplier_string = "1";
            }
            
            long long int multiplier = stoll(multiplier_string);

            // multiplying elements in stack 
            // and adding that back in stack 
            vector<pair<string, long long int>> temp;
            while(!s.empty()) {
                auto top = s.top();
                s.pop();
                if(top.first == "(") break;
                temp.push_back({top.first, top.second * multiplier});
            }

            for(auto p : temp) {
                s.push(p);
            }
            
        } 
        
        // encountered a normal Atom with its Count
        else {
            auto curr_element = getAtomAndCount(formula, i);
            if(s.empty()) { // stack is empty => add in final map itself
                final_map[curr_element.first] += curr_element.second;
            } else { // push in stack
                s.push({curr_element.first, curr_element.second});
            }
        }
    }

    while(!s.empty()) {
        auto top = s.top();
        final_map[top.first] += top.second;
        s.pop();
    }

    string result = "";
    for(auto p : final_map) {
        result += p.first + (p.second == 1 ? "" : to_string(p.second)); 
    }

    return result;
}

// "H2O"
// "H2O(A2H4(Gk2(G2A)9DF)3)4J6H3"
// "((N42)24(OB40Li30CHe3O48LiNN26)33(C12Li48N30H13HBe31)21(BHN30Li26BCBe47N40)15(H5)16)14"
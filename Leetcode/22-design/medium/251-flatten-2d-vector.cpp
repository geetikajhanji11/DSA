/*******************************************************************

*******************************************************************/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Vector2D {
    vector<vector<int>> v;
    int i;
    int j;
    int rows;

public:
    Vector2D(vector<vector<int>>& vec2d) {
        this->i = 0;
        this->j = 0;

        for(auto vec1d : vec2d) {
            if(vec1d.size() == 0) continue;
            this->v.push_back(vec1d);
        }

        this->rows = v.size();
    }

    int next() {
        int ans = v[i][j];
        j++;
        if(j == v[i].size()) {
            i++;
            j = 0;
        }
        return ans;
    }

    bool hasNext() {
        return i < rows && j < v[i].size();
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
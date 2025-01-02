#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) { 
        // The minimum number of cities to rebuild is the minimum of n or m
        return std::min(n, m);
    }
};


#endif
#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) { 
        // To reconstruct all cities, we need to either rebuild one full row or one full column
        return std::min(n, m);
    }
};


#endif
#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) { 
        // The minimum number of cities needed to be rebuilt is the minimum
        // of either creating one entire row or one entire column rebuilt.
        return min(n, m);
    }
};


#endif
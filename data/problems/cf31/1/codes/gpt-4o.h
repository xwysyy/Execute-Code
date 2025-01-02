#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        // Using a checkerboard strategy to minimize the number of cities to be rebuilt
        return ((n + 1) / 2) * ((m + 1) / 2);
    }
};


#endif
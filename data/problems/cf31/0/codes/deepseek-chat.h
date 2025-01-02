#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        // If either n or m is 1, the minimum number of cities to rebuild is the maximum of n and m
        if (n == 1 || m == 1) {
            return max(n, m);
        }
        // Otherwise, the minimum number of cities to rebuild is ceil(n / 2) * ceil(m / 2)
        return ((n + 1) / 2) * ((m + 1) / 2);
    }
};


#endif
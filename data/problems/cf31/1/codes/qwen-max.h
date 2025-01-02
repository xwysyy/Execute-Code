#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) { 
        if (n == 1 || m == 1) {
            return std::max(n, m);
        }
        if (n % 2 == 0 && m % 2 == 0) {
            return n * m / 2;
        } else if (n % 2 == 0 || m % 2 == 0) {
            return (n * m + 1) / 2;
        } else {
            return (n * m + 1) / 2;
        }
    }
};

#endif
#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &m) {
        if (n == 1 && m == 1) {
            return 1;
        }
        if (n == 1 || m == 1) {
            return 1;
        }
        return (n * m + 1) / 2;
    }
};


#endif
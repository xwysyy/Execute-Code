#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        int operations = 0;
        for (int i = 0; i < n; ++i) {
            while (p[i] != i + 1 && p[p[i] - 1] != i + 1) {
                swap(p[i], p[p[i] - 1]);
                operations++;
            }
        }
        return operations;
    }
};


#endif
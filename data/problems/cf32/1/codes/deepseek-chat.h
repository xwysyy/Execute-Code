#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int n, vector<pair<int, int>> &edges) {
        if (n == 1) return 0;
        vector<int> degree(n + 1, 0);
        for (auto &edge : edges) {
            degree[edge.first]++;
            degree[edge.second]++;
        }
        int leafCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (degree[i] == 1) {
                leafCount++;
            }
        }
        return (leafCount + 1) / 2;
    }
};


#endif
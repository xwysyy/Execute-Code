#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n + 1, false);
        int operations = 0;

        for (int i = 1; i <= n; ++i) {
            if (visited[i] || p[i - 1] == i) {
                continue;
            }

            int j = i;
            int cycleSize = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = p[j - 1];
                cycleSize++;
            }

            if (cycleSize > 2) {
                operations += (cycleSize + 1) / 2;
            }
        }

        return operations;
    }
};

#endif
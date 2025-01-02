#ifndef GEMINI_1_5_PRO_H
#define GEMINI_1_5_PRO_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        int count = 0;
        vector<bool> visited(n + 1, false);
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                if (p[i - 1] == i) {
                    visited[i] = true;
                } else if (p[p[i - 1] - 1] == i) {
                    visited[i] = true;
                    visited[p[i - 1]] = true;
                } else {
                    count++;
                    visited[i] = true;
                    int current = p[i - 1];
                    while (!visited[current]) {
                        visited[current] = true;
                        current = p[current - 1];
                    }
                }
            }
        }
        return count;
    }
};


#endif
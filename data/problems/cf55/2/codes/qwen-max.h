#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n, false);
        int operations = 0;
        
        for (int i = 0; i < n; ++i) {
            if (visited[i] || p[i] == i + 1) {
                continue;
            }
            
            int j = i;
            int cycleSize = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = p[j] - 1;
                cycleSize++;
            }
            
            if (cycleSize > 2) {
                operations += cycleSize / 2;
            } else if (cycleSize == 2) {
                operations += 1;
            }
        }
        
        return operations;
    }
};

#endif
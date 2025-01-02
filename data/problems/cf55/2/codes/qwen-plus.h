#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {   
        int operations = 0;
        std::vector<bool> visited(n, false);

        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                int cycle_size = 0;
                for (int j = i; !visited[j]; j = p[j] - 1) {
                    visited[j] = true;
                    ++cycle_size;
                }
                
                // If the cycle size is greater than 2, it needs to be broken down
                if (cycle_size > 2) {
                    operations += cycle_size - 2;
                }
            }
        }

        return operations;
    }
};


#endif
#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {
        vector<bool> visited(n + 1, false);
        int operations = 0;
        
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                int cycle_length = 0;
                int current = i;
                
                // Follow the cycle
                while (!visited[current]) {
                    visited[current] = true;
                    current = p[current - 1]; // Convert 1-based index to 0-based
                    cycle_length++;
                }
                
                // For a cycle of length k, we need (k - 1) swaps to make it simple
                if (cycle_length > 1) {
                    operations += (cycle_length - 1);
                }
            }
        }
        
        return operations;
    }
};


#endif
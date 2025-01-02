#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int operations = 0;
        int twos_needed = n;
        vector<bool> used(n + 1, false);
        
        for (int i = 0; i < n && twos_needed > 0; ++i) {
            int count = 0;
            int current = a[i];
            while (current % 2 == 0) {
                current /= 2;
                count++;
            }
            if (count > 0) {
                twos_needed -= count;
                used[i + 1] = true;
            }
        }
        
        for (int i = 1; i <= n && twos_needed > 0; ++i) {
            if (!used[i]) {
                int count = 0;
                int current = i;
                while (current % 2 == 0) {
                    current /= 2;
                    count++;
                }
                twos_needed -= count;
                operations++;
            }
        }
        
        return twos_needed > 0 ? -1 : operations;
    }
};

#endif
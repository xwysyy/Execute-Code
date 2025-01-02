#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &p) {   
        int operations = 0;
        for (int i = 1; i <= n; ++i) {
            int j = i;
            while (p[j - 1] != i && p[j - 1] != p[p[j - 1] - 1]) {
                swap(p[j - 1], p[p[j - 1] - 1]);
                operations++;
            }
        }
        // Check if the permutation is already simple
        bool isSimple = true;
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] != i && p[p[i - 1] - 1] != i) {
                isSimple = false;
                break;
            }
        }
        if (isSimple) return operations;

        // If not simple, we need to make it simple by additional swaps
        for (int i = 1; i <= n; ++i) {
            if (p[i - 1] != i && p[p[i - 1] - 1] != i) {
                for (int j = 1; j <= n; ++j) {
                    if (p[j - 1] == i || p[p[j - 1] - 1] == i) {
                        swap(p[i - 1], p[j - 1]);
                        operations++;
                        break;
                    }
                }
            }
        }
        return operations;
    }
};


#endif
#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long count = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (a[i][j] < 0) {
                    // Calculate the number of operations needed to make a[i][j] >= 0
                    long long operations = -a[i][j];
                    count += operations;
                    // Apply the operations to the diagonal starting at (i,j)
                    for (int k = 0; k < n - max(i, j); ++k) {
                        a[i + k][j + k] += operations;
                    }
                }
            }
        }
        return count;
    }
};


#endif
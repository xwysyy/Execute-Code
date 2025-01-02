#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {   
        long long totalOperations = 0;
        vector<vector<int>> operations(n, vector<int>(n, 0));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int currentHeight = a[i][j] + operations[i][j];
                if (currentHeight < 0) {
                    int neededOps = -currentHeight;
                    totalOperations += neededOps;

                    // Apply operations on this diagonal
                    for (int k = 0; k + i < n && k + j < n; ++k) {
                        operations[i + k][j + k] += neededOps;
                    }
                }
            }
        }
        
        return totalOperations;
    }
};


#endif
#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long operations = 0;

        // Iterate over diagonals starting from the bottom-right, moving to the top-left
        for (int start = n-1; start >= 0; --start) {
            for (int i = start, j = start; i < n && j < n; ++i, ++j) {
                if (a[i][j] < 0) {
                    // Calculate how much we need to increment this diagonal cell
                    int increment = -a[i][j];
                    operations += increment; // Count the operations needed
                    // Apply the increment to the diagonal starting from (i, j)
                    for (int k = 0; k <= i - start; ++k) {
                        a[start + k][start + k] += increment;
                    }
                }
            }
        }
        return operations;
    }
};


#endif
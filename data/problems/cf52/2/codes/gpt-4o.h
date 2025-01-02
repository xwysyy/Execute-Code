#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, std::vector<std::vector<int>> &a) {
        long long operations = 0;

        // Start iterating from the bottom row upwards
        for(int i = n - 1; i >= 0; --i) {
            for(int j = n - 1; j >= 0; --j) {
                // a[i][j] is the current element
                if (a[i][j] < 0) {
                    // Determine how many operations are needed to make this element non-negative
                    int required = -a[i][j]; // since a[i][j] is negative, -a[i][j] is the positive needed to zero it
                    operations += required;

                    // Apply this operation along the diagonal starting from (i, j)
                    int x = i, y = j;
                    while (x < n && y < n) {
                        a[x][y] += required; // increment each diagonal element by "required"
                        x++;
                        y++;
                    }
                }
            }
        }

        return operations;
    }
};


#endif
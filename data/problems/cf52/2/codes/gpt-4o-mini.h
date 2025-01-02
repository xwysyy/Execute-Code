#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long operations = 0; // To count the total operations required
        
        // Traverse the matrix from bottom right to top left
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                // If we find a negative height at (i, j), we need to perform operations
                if (a[i][j] < 0) {
                    // The number of operations needed to make the value at (i, j) at least 0.
                    long long needed = -a[i][j]; // because a[i][j] is negative
                    
                    // Increment this position with the needed operations
                    operations += needed;
                    
                    // We will also affect the diagonal positions
                    for (int k = 0; k < needed; ++k) {
                        // Update the diagonals only if within bounds
                        if (i - k >= 0 && j - k >= 0) {
                            a[i - k][j - k] += 1; // Increment the diagonal affecting cell
                        }
                    }
                }
            }
        }
        
        return operations; // Return the total operations counted
    }
};


#endif
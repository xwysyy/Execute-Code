#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<vector<int>> &a) {
        long long total_operations = 0;
        vector<long long> required_increases(n, 0);
        
        // Iterate through the matrix to find the required increases
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                // If the current element is negative
                if (a[i][j] < 0) {
                    long long needed = -a[i][j]; // How many increases are needed
                    int diagonal_index = j - i; // Calculate the diagonal index

                    // Only update the required_increases for the valid diagonal index
                    if (diagonal_index >= 0 && diagonal_index < n) {
                        required_increases[diagonal_index] = max(required_increases[diagonal_index], needed);
                    }
                }
            }
        }

        // Sum up all the required increases
        for (int k = 0; k < n; ++k) {
            total_operations += required_increases[k];
        }

        return total_operations;
    }
};


#endif
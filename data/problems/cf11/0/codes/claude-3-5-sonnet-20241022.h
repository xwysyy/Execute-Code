#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Count total number of 2's in the product
        int total_twos = 0;
        for (int x : a) {
            int num = x;
            while (num % 2 == 0) {
                total_twos++;
                num /= 2;
            }
        }
        
        // If we already have enough 2's, return 0
        if (total_twos >= n) return 0;
        
        // Calculate how many more 2's we need
        int need = n - total_twos;
        
        // For each index i, calculate how many 2's we can get
        vector<int> twos_from_index;
        for (int i = 1; i <= n; i++) {
            int num = i;
            int count = 0;
            while (num % 2 == 0) {
                count++;
                num /= 2;
            }
            twos_from_index.push_back(count);
        }
        
        // Sort in descending order to get maximum 2's first
        sort(twos_from_index.rbegin(), twos_from_index.rend());
        
        // Try to accumulate enough 2's
        int operations = 0;
        int collected = 0;
        
        for (int twos : twos_from_index) {
            if (collected >= need) break;
            if (twos > 0) {
                collected += twos;
                operations++;
            }
        }
        
        // Check if we collected enough 2's
        return (collected >= need) ? operations : -1;
    }
};


#endif
#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Count initial number of 2's in the product
        long long total_twos = 0;
        for (int x : a) {
            int count = 0;
            while (x % 2 == 0) {
                count++;
                x /= 2;
            }
            total_twos += count;
        }
        
        // Calculate how many more 2's we need
        long long target = n;
        if (total_twos >= target) return 0;
        
        // For each index i, calculate how many 2's we can get
        vector<int> twos_from_index;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            int num = i;
            while (num % 2 == 0) {
                count++;
                num /= 2;
            }
            twos_from_index.push_back(count);
        }
        
        // Sort in descending order to get maximum 2's first
        sort(twos_from_index.rbegin(), twos_from_index.rend());
        
        // Try to reach target using available operations
        int operations = 0;
        for (int twos : twos_from_index) {
            if (total_twos >= target) break;
            if (twos > 0) {
                total_twos += twos;
                operations++;
            }
        }
        
        return (total_twos >= target) ? operations : -1;
    }
};


#endif
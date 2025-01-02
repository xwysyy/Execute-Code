#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int current_twos = 0;
        vector<int> factors_needed;
        
        // Count the current number of 2s in the product
        for (int number : a) {
            int count = 0;
            while (number % 2 == 0) {
                count++;
                number /= 2;
            }
            current_twos += count;
        }
        
        // If we already have enough factors of 2
        if (current_twos >= n) return 0;

        // Calculate how many more factors of 2 we need
        int to_add = n - current_twos;
        
        // Work through indices, `i` from 1 to n, to see how many factors of 2 they can provide
        for (int i = 1; i <= n; i++) {
            int additional_factors = 0;
            int idx = i;
            // Count factors of 2 in `i`
            while (idx % 2 == 0) {
                additional_factors++;
                idx /= 2;
            }
            if (additional_factors > 0) {
                factors_needed.push_back(additional_factors);
            }
        }
        
        // Sort factors_needed in descending order to use the most effective ops first
        sort(factors_needed.rbegin(), factors_needed.rend());
        
        // Try to satisfy the 'to_add' requirement using the largest available factors
        int operations = 0;
        for (int factor : factors_needed) {
            to_add -= factor;
            operations++;
            if (to_add <= 0) break;
        }
        
        // If we still need more factors, it's impossible
        return (to_add > 0) ? -1 : operations;
    }
};


#endif
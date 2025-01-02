#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Calculate the total number of factors of 2 in the product of the array
        int total_factors = 0;
        for (int num : a) {
            while (num % 2 == 0) {
                total_factors++;
                num /= 2;
            }
        }
        
        // If the total factors are already >= n, no operations are needed
        if (total_factors >= n) {
            return 0;
        }
        
        // Otherwise, we need to find the minimum number of operations
        // Each operation can add at most log2(i) factors of 2
        // We need to select a subset of indices to maximize the number of factors added
        // We can sort the indices based on the number of factors they can add
        
        vector<int> factors(n, 0);
        for (int i = 0; i < n; ++i) {
            int idx = i + 1; // Since indices are 1-based
            int cnt = 0;
            while (idx % 2 == 0) {
                cnt++;
                idx /= 2;
            }
            factors[i] = cnt;
        }
        
        // Sort the factors in descending order
        sort(factors.rbegin(), factors.rend());
        
        int operations = 0;
        for (int f : factors) {
            total_factors += f;
            operations++;
            if (total_factors >= n) {
                return operations;
            }
        }
        
        // If we cannot achieve the required number of factors, return -1
        return -1;
    }
};


#endif
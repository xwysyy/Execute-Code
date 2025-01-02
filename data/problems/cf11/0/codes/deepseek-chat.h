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
        
        // Otherwise, we need to find the minimum number of operations to add factors of 2
        // We can only multiply each element by its index once
        // So we need to find the indices that, when multiplied, add the most factors of 2
        
        // Create a vector to store the additional factors of 2 we can get by multiplying each element by its index
        vector<int> additional_factors(n, 0);
        for (int i = 0; i < n; ++i) {
            int index = i + 1; // Since indices start from 1
            int temp = a[i] * index;
            int count = 0;
            while (temp % 2 == 0) {
                count++;
                temp /= 2;
            }
            additional_factors[i] = count - (a[i] % 2 == 0 ? 1 : 0); // Subtract the existing factors of 2 in a[i]
        }
        
        // Sort the additional_factors in descending order
        sort(additional_factors.rbegin(), additional_factors.rend());
        
        // Now, we need to select the top k operations to add enough factors of 2
        int operations = 0;
        for (int factor : additional_factors) {
            if (factor <= 0) break; // No more factors can be added
            total_factors += factor;
            operations++;
            if (total_factors >= n) {
                return operations;
            }
        }
        
        // If we couldn't add enough factors, return -1
        return -1;
    }
};


#endif
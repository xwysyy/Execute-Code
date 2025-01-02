#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, vector<int> &a) {
        long long maxProduct = LLONG_MIN; // Initialize to the smallest possible value
        
        for (int i = 0; i < n - 1; i++) {
            // Calculate the product of adjacent elements
            long long product = static_cast<long long>(a[i]) * a[i + 1];
            // Update maxProduct if the current product is greater
            if (product > maxProduct) {
                maxProduct = product;
            }
        }
        
        return maxProduct; // Return the maximum beauty of adjacent pairs
    }
};


#endif
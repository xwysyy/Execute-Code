#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, int &m, vector<int> &a, vector<int> &b) {
        // Step 1: Sort both arrays
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        long long maxDifference = 0;
        
        // Step 2: Use greedy approach to maximize differences
        // Pick the largest available values from b for smallest values of a
        int j = m - 1;  // Start from largest element in b
        for (int i = 0; i < n; ++i) {
            maxDifference += abs(a[i] - b[j]);  // Maximize the difference
            j--;  // Pick next largest for the next comparison
        }
        
        return maxDifference;
    }
};


#endif
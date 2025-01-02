#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<long long, int> freq; // Use long long to avoid overflow
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= n; j++) {
                long long value = (long long)a[i] + j; // Calculate adjusted value
                freq[value]++; // Increment the frequency count
            }
        }
        
        int maxFrequency = 0;
        for (const auto &entry : freq) {
            maxFrequency = max(maxFrequency, entry.second); // Find maximum frequency
        }
        
        return maxFrequency; // Return the result
    }
};


#endif
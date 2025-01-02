#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Map to count the frequency of each topic
        unordered_map<int, int> freq;
        
        // Calculate the initial disturbance and frequency of each topic
        int initial_disturbance = 0;
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
            if (i > 0 && a[i] == a[i - 1]) {
                initial_disturbance++;
            }
        }
        
        // Find the maximum frequency of any topic
        int max_freq = 0;
        for (const auto& pair : freq) {
            max_freq = max(max_freq, pair.second);
        }

        // The total number of swaps we can achieve is n // 2
        int half_n = (n + 1) / 2; // This gives us the effective usable slots
        
        // Calculate the minimum disturbances we can achieve
        // It's the initial disturbance minus the number of pairings we can effectively control
        int min_disturbance = initial_disturbance - min(max_freq - 1, half_n);
        
        // We cannot have negative disturbances, make sure to return at least zero
        return max(min_disturbance, 0);
    }
};


#endif
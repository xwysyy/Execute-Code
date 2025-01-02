#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        unordered_map<int, int> freq;
        
        // Count frequency of each topic
        for (int i = 0; i < n; i++) {
            freq[a[i]]++;
        }

        // Find the maximum frequency
        int max_freq = 0;
        for (const auto& p : freq) {
            max_freq = max(max_freq, p.second);
        }

        // Calculate the minimum disturbances
        int total_pairs = n - 1; // total pairs that we can disturb
        int min_disturbance = total_pairs - (max_freq - 1); // max possible separations with remaining unique topics

        // Ensure min disturbance is at least 0
        return max(min_disturbance, 0);
    }
};


#endif
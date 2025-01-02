#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        int disturbance = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (a[i] == a[i + 1]) {
                ++disturbance;
            }
        }

        // Create a frequency map to count occurrences of each topic
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
        }

        // Calculate the minimum disturbance after possible swaps
        int min_disturbance = disturbance;
        for (int i = 0; i < n / 2; ++i) {
            if (a[i] == a[n - i - 1]) {
                continue;
            }
            int new_disturbance = disturbance;
            if (a[i] == a[i + 1]) {
                --new_disturbance;
            }
            if (a[n - i - 1] == a[n - i - 2]) {
                --new_disturbance;
            }
            if (a[i] == a[n - i - 2]) {
                ++new_disturbance;
            }
            if (a[n - i - 1] == a[i + 1]) {
                ++new_disturbance;
            }
            min_disturbance = min(min_disturbance, new_disturbance);
        }

        return min_disturbance;
    }
};

#endif
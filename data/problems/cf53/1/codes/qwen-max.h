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
                disturbance++;
            }
        }

        // Create a frequency map to count the occurrences of each topic
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
        }

        // Calculate the minimum possible disturbance
        int min_disturbance = 0;
        for (auto &entry : freq) {
            int count = entry.second;
            min_disturbance += max(0, count - (n - count));
        }

        // The actual minimal disturbance is half of the calculated value
        return max(0, (min_disturbance / 2));
    }
};

#endif
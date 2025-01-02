#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // We will count the number of disturbances in the original arrangement
        int initialDisturbance = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] == a[i - 1]) {
                initialDisturbance++;
            }
        }

        // We need to use a map to count the frequency of each topic of interest
        unordered_map<int, int> frequency;
        for (int i = 0; i < n; i++) {
            frequency[a[i]]++;
        }

        // The maximum frequency will tell us the best arrangement possible
        int maxFrequency = 0;
        for (const auto &entry : frequency) {
            maxFrequency = max(maxFrequency, entry.second);
        }

        // The minimum disturbance can be derived from the formula:
        // Disturbance can be minimized to n - maxFrequency
        int minDisturbance = n - maxFrequency;

        // Return the minimum disturbance that can be achieved
        return minDisturbance;
    }
};


#endif
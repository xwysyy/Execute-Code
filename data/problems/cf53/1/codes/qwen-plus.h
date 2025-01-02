#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Create a frequency map to count occurrences of each topic
        unordered_map<int, int> freq;
        for (int i = 0; i < n; ++i) {
            freq[a[i]]++;
        }

        // Calculate the maximum frequency of any single topic
        int maxFreq = 0;
        for (auto &entry : freq) {
            maxFreq = max(maxFreq, entry.second);
        }

        // If the most frequent topic appears more than half the time, 
        // it will always have at least one pair with its neighbor.
        if (maxFreq > (n + 1) / 2) {
            return maxFreq - 1;
        } else {
            // Otherwise, we can arrange the students such that no two adjacent students
            // have the same topic by swapping symmetrically.
            return 0;
        }
    }
};


#endif
#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {   
        // Create a frequency map of all elements
        unordered_map<int, int> freq;
        for (int i : a) {
            freq[i]++;
        }

        // Calculate the maximum frequency of any single element
        int maxFreq = 0;
        for (auto &[topic, count] : freq) {
            maxFreq = max(maxFreq, count);
        }

        // If all elements are the same, we can only have at most one pair of identical neighbors after swaps
        if (maxFreq > n / 2) {
            return maxFreq - (n - maxFreq);
        }

        // Otherwise, we can always arrange the elements such that no two adjacent elements are the same
        return max(0, maxFreq - 1);
    }
};


#endif
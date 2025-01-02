#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to make it easier to find the optimal permutation
        sort(a.begin(), a.end());
        
        // The idea is to use the smallest permutation [1, 2, ..., n] and add it to the sorted array
        // This will ensure that the differences between consecutive elements are minimized
        int maxFreq = 1;
        int currentFreq = 1;
        
        for (int i = 1; i < n; ++i) {
            // Calculate the new value after adding the permutation
            int newValue = a[i] + (i + 1);
            int prevValue = a[i - 1] + i;
            
            // If the new value is the same as the previous value, increment the current frequency
            if (newValue == prevValue) {
                currentFreq++;
            } else {
                // Otherwise, update the maximum frequency and reset the current frequency
                maxFreq = max(maxFreq, currentFreq);
                currentFreq = 1;
            }
        }
        
        // Update the maximum frequency one last time in case the last sequence of equal values is the longest
        maxFreq = max(maxFreq, currentFreq);
        
        return maxFreq;
    }
};

#endif
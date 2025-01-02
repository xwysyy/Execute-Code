#ifndef QWEN_MAX_H
#define QWEN_MAX_H
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int &n, vector<int> &a) {
        // Sort the array to make it easier to find the best permutation
        sort(a.begin(), a.end());
        
        // The best strategy is to add the smallest available permutation value to the largest available array value
        // This way, we can maximize the frequency of the most frequent element
        int maxFreq = 1;
        for (int i = 1; i < n; ++i) {
            // Calculate the difference between consecutive elements
            int diff = a[i] - a[i - 1];
            // If the difference is less than or equal to 1, we can make these two elements equal by adding a suitable permutation
            if (diff <= 1) {
                maxFreq++;
            } else {
                // Otherwise, reset the frequency
                maxFreq = 1;
            }
        }
        
        return maxFreq;
    }
};

#endif
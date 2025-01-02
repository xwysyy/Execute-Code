#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        // Create a map to store differences between elements
        map<int, int> freq;
        
        // For each pair of elements, calculate how much we need to add
        // to the smaller element to make it equal to the larger element
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // If a[i] <= a[j], we need to add (a[j] - a[i]) to a[i]
                // If a[i] > a[j], we need to add (a[i] - a[j]) to a[j]
                int diff = abs(a[i] - a[j]);
                if(diff <= n) {
                    freq[diff]++;
                }
            }
        }
        
        // Initialize result with 1 (we can always have at least 1 element)
        int result = 1;
        
        // For each difference d
        for(auto [diff, count] : freq) {
            // Count how many pairs of elements we can make equal
            // by using numbers from 1 to n in our permutation
            int equalPairs = 0;
            for(int i = 0; i < n; i++) {
                for(int j = i + 1; j < n; j++) {
                    if(abs(a[i] - a[j]) == diff && diff <= n) {
                        equalPairs++;
                    }
                }
            }
            
            // Update result if we can make more elements equal
            result = max(result, equalPairs + 1);
        }
        
        return result;
    }
};


#endif
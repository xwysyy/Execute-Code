#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, vector<int> &a) {
        unordered_map<int, int> prefixIndices;
        int prefix_sum = 0;
        int count = 0;
        int last_index = -1; // To track the last used index for a non-overlapping segment
        
        for (int i = 0; i < n; ++i) {
            prefix_sum += a[i];

            // Check if the current prefix sum is zero
            if (prefix_sum == 0) {
                count++;
                last_index = i; // Update last_index to current index
                prefix_sum = 0; // Reset since this segment has been taken
            }
            // Check if we have seen this prefix sum before
            else if (prefixIndices.find(prefix_sum) != prefixIndices.end()) {
                // We can only use this segment if it starts after the last counted segment
                if (prefixIndices[prefix_sum] > last_index) {
                    count++;
                    last_index = i; // Update last_index to current index
                }
            }
            // Update or insert the current prefix sum with the current index
            prefixIndices[prefix_sum] = i;
        }
        
        return count;
    }
};


#endif
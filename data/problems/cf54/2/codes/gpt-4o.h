#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, std::vector<int> &a) {
        std::unordered_map<int, int> prefixMap;
        int prefixSum = 0;
        int lastEnd = -1; // End of the last found beautiful segment
        int beautifulCount = 0;

        for (int i = 0; i < n; ++i) {
            prefixSum += a[i];

            // Check if we directly have a zero-sum segment from the start
            if (prefixSum == 0) {
                beautifulCount++;
                lastEnd = i;
            } else if (prefixMap.find(prefixSum) != prefixMap.end()) {
                // Check for zero-sum subarray ending at the current index
                int lastIndex = prefixMap[prefixSum];
                if (lastIndex >= lastEnd) {
                    beautifulCount++;
                    lastEnd = i;
                }
            }

            // Add or update the prefix sum index
            prefixMap[prefixSum] = i;
        }

        return beautifulCount;
    }
};


#endif
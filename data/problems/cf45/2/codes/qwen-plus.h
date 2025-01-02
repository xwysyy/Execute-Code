#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {   
        // Sort the array to facilitate grouping flowers with similar petals
        sort(a.begin(), a.end());
        
        // Create a frequency map for consecutive petal counts
        vector<pair<int, int>> groups;
        for (int i = 0; i < n; ) {
            int j = i;
            while (j < n && a[j] == a[i]) ++j;
            groups.emplace_back(a[i], j - i);
            i = j;
        }
        
        // Initialize variables for dynamic programming approach
        int groupCount = groups.size();
        vector<long long> dp(groupCount + 1, 0), sum(groupCount + 1, 0);
        
        // Iterate over each group of flowers
        for (int i = 1; i <= groupCount; ++i) {
            int petal = groups[i - 1].first;
            int count = groups[i - 1].second;
            
            // Calculate the total cost if this group is included
            long long totalCost = (long long)petal * count;
            long long maxPetals = 0;
            
            // Check if we can include this group and the previous one
            if (i > 1 && groups[i - 2].first + 1 == petal) {
                long long prevTotalCost = (long long)groups[i - 2].first * groups[i - 2].second;
                if (totalCost + prevTotalCost <= m) {
                    maxPetals = (long long)petal * count + (long long)groups[i - 2].first * groups[i - 2].second;
                    maxPetals += dp[i - 2];
                } else if (prevTotalCost <= m) {
                    maxPetals = (long long)groups[i - 2].first * groups[i - 2].second + dp[i - 2];
                }
            }
            
            // Check if we can only include this group
            if (totalCost <= m) {
                maxPetals = max(maxPetals, (long long)petal * count + dp[i - 1]);
            }
            
            // Update DP table
            dp[i] = max(dp[i - 1], maxPetals);
        }
        
        return dp[groupCount];
    }
};


#endif
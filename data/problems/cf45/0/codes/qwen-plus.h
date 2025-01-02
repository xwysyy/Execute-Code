#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {   
        // Sort the flowers based on the number of petals
        sort(a.begin(), a.end());
        
        // Create a frequency map to count occurrences of each petal count
        map<int, int> freq;
        for (int petal : a) {
            freq[petal]++;
        }
        
        // Create a list of unique petal counts
        vector<int> uniquePetalCounts;
        for (auto &entry : freq) {
            uniquePetalCounts.push_back(entry.first);
        }
        
        int len = uniquePetalCounts.size();
        long long maxPetals = 0;
        
        // Iterate through each unique petal count and try to form bouquets
        for (int i = 0; i < len; ++i) {
            int currentPetalCount = uniquePetalCounts[i];
            int nextPetalCount = (i + 1 < len) ? uniquePetalCounts[i + 1] : -1;
            
            // Check if the difference between consecutive petal counts is 1 or less
            if (nextPetalCount == -1 || nextPetalCount - currentPetalCount <= 1) {
                long long totalCost = 0;
                long long totalPetals = 0;
                
                // Try to add as many flowers with the current petal count as possible
                for (int j = i; j < len && (j == i || uniquePetalCounts[j] - uniquePetalCounts[j - 1] <= 1); ++j) {
                    int count = freq[uniquePetalCounts[j]];
                    for (int k = 0; k < count; ++k) {
                        if (totalCost + uniquePetalCounts[j] <= m) {
                            totalCost += uniquePetalCounts[j];
                            totalPetals += uniquePetalCounts[j];
                        } else {
                            break;
                        }
                    }
                    if (totalCost > m) break;
                }
                
                maxPetals = max(maxPetals, totalPetals);
            }
        }
        
        return maxPetals;
    }
};


#endif
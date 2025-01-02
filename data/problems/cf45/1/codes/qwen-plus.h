#ifndef QWEN_PLUS_H
#define QWEN_PLUS_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long solve(int &n, long long &m, vector<int> &a) {   
        // Sort the flowers by the number of petals
        sort(a.begin(), a.end());
        
        // Frequency map to count occurrences of each petal count
        map<int, int> freq;
        for (int petal : a) {
            freq[petal]++;
        }
        
        // Store the cumulative cost and cumulative petals for consecutive petal counts
        vector<pair<long long, long long>> groups;
        int currentPetal = -1;
        long long cumulativeCost = 0;
        long long cumulativePetals = 0;
        
        for (const auto& entry : freq) {
            if (entry.first != currentPetal + 1) {
                if (cumulativeCost > 0) {
                    groups.push_back({cumulativeCost, cumulativePetals});
                }
                cumulativeCost = 0;
                cumulativePetals = 0;
            }
            cumulativeCost += (long long)entry.first * entry.second;
            cumulativePetals += entry.second;
            currentPetal = entry.first;
        }
        if (cumulativeCost > 0) {
            groups.push_back({cumulativeCost, cumulativePetals});
        }
        
        // Try to maximize the total number of petals within the budget
        long long maxPetals = 0;
        for (auto& group : groups) {
            long long cost = 0;
            long long petals = 0;
            for (auto& g : groups) {
                if (abs(g.second - group.second) <= 1) {
                    if (cost + g.first <= m) {
                        cost += g.first;
                        petals += (long long)g.second * (g.first / g.second);
                    } else {
                        // If adding this group exceeds the budget, add as many flowers as possible
                        int numFlowers = (m - cost) / g.first * g.second;
                        petals += numFlowers;
                        break;
                    }
                }
            }
            maxPetals = max(maxPetals, petals);
        }
        
        return maxPetals;
    }
};


#endif
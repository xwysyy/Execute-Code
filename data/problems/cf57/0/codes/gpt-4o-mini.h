#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        unordered_map<int, vector<int>> brandCosts;
        
        // Group prices by brand
        for (const auto& bottle : b) {
            int brand = bottle.first;
            int cost = bottle.second;
            brandCosts[brand].push_back(cost);
        }
        
        int totalProfit = 0;
        
        // For each brand, calculate the potential earnings
        for (const auto& entry : brandCosts) {
            const vector<int>& costs = entry.second;
            // Sort costs in descending order
            vector<int> sortedCosts = costs;
            sort(sortedCosts.rbegin(), sortedCosts.rend());
            
            // Take the maximum costs for up to `n` shelves
            for (int i = 0; i < min(n, (int)sortedCosts.size()); ++i) {
                totalProfit += sortedCosts[i];
            }
        }
        
        return totalProfit;
    }
};


#endif
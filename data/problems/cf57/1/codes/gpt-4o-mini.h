#ifndef GPT_4O_MINI_H
#define GPT_4O_MINI_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Create a map to track the maximum cost of each brand
        unordered_map<int, int> brandMaxCost;
        
        // Iterate through the bottles to find the maximum cost for each brand
        for (const auto& bottle : b) {
            int brand = bottle.first;
            int cost = bottle.second;
            brandMaxCost[brand] = max(brandMaxCost[brand], cost);
        }

        // Now we have the maximum cost for each brand, we just need to select the top `n`
        vector<int> maxCosts;
        for (const auto& entry : brandMaxCost) {
            maxCosts.push_back(entry.second);
        }

        // Sort the maximum costs in descending order
        sort(maxCosts.rbegin(), maxCosts.rend());

        // Calculate the maximum amount we can earn by placing bottles in shelves
        int totalEarnings = 0;
        for (int i = 0; i < min(n, (int)maxCosts.size()); i++) {
            totalEarnings += maxCosts[i];
        }

        return totalEarnings;
    }
};


#endif
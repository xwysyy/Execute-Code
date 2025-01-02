#ifndef CLAUDE_3_5_SONNET_20241022_H
#define CLAUDE_3_5_SONNET_20241022_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &b) {
        // Group bottles by brand and sort by cost
        map<int, vector<int>> brandGroups;
        for (const auto &bottle : b) {
            brandGroups[bottle.first].push_back(bottle.second);
        }
        
        // Sort costs in descending order for each brand
        vector<int> allCosts;
        for (auto &group : brandGroups) {
            sort(group.second.begin(), group.second.end(), greater<int>());
            // Add all costs to a single vector
            allCosts.insert(allCosts.end(), group.second.begin(), group.second.end());
        }
        
        // Sort all costs in descending order
        sort(allCosts.begin(), allCosts.end(), greater<int>());
        
        // Take k highest costs or all costs if k is smaller
        int maxProfit = 0;
        for (int i = 0; i < min(k, (int)allCosts.size()); i++) {
            maxProfit += allCosts[i];
        }
        
        return maxProfit;
    }
};


#endif
#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, std::vector<std::pair<int, int>> &b) {
        // Step 1: Group bottles by brand
        std::map<int, std::vector<int>> brandCosts;
        for (const auto& bottle : b) {
            int brand = bottle.first;
            int cost = bottle.second;
            brandCosts[brand].push_back(cost);
        }

        // Step 2 & 3: Sort and collect the top costs for each brand
        std::vector<int> allMaxCosts;
        for (auto& [brand, costs] : brandCosts) {
            std::sort(costs.begin(), costs.end(), std::greater<int>());
            allMaxCosts.insert(allMaxCosts.end(), costs.begin(), costs.end());
        }

        // Step 4: Sort the collected maximum costs across all brands
        std::sort(allMaxCosts.begin(), allMaxCosts.end(), std::greater<int>());

        // Step 5: Sum up the top `n` highest costs to maximize revenue
        int maxRevenue = 0;
        for (int i = 0; i < n && i < allMaxCosts.size(); ++i) {
            maxRevenue += allMaxCosts[i];
        }

        return maxRevenue;
    }
};


#endif
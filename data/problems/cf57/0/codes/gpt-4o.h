#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, vector<pair<int, int>> &bottles) {
        // Create a map to store the maximum cost for each brand
        unordered_map<int, int> brand_max_cost;

        // Iterate over each bottle
        for (const auto& bottle : bottles) {
            int brand = bottle.first;
            int cost = bottle.second;

            // Update the maximum cost for each brand
            if (brand_max_cost.find(brand) != brand_max_cost.end()) {
                brand_max_cost[brand] = max(brand_max_cost[brand], cost);
            } else {
                brand_max_cost[brand] = cost;
            }
        }

        // Collect all maximum costs
        vector<int> max_costs;
        for (const auto& entry : brand_max_cost) {
            max_costs.push_back(entry.second);
        }

        // Sort these costs in descending order
        sort(max_costs.begin(), max_costs.end(), greater<int>());

        // Calculate the maximum revenue for n shelves
        int max_revenue = 0;
        for (int i = 0; i < n && i < max_costs.size(); ++i) {
            max_revenue += max_costs[i];
        }

        return max_revenue;
    }
};


#endif
#ifndef GPT_4O_H
#define GPT_4O_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, std::vector<std::pair<int, int>> &b) {
        // Step 1: Group bottles by brand
        std::unordered_map<int, std::vector<int>> brand_to_costs;
        
        for (const auto &bottle : b) {
            int brand = bottle.first;
            int cost = bottle.second;
            brand_to_costs[brand].push_back(cost);
        }
        
        // Step 2: For each brand, sort the costs in descending order
        std::vector<int> max_earnings;
        for (auto &[brand, costs] : brand_to_costs) {
            std::sort(costs.begin(), costs.end(), std::greater<int>());
            // accumulate the total cost for this brand
            int total_cost = 0;
            for (const int cost : costs) {
                total_cost += cost;
            }
            max_earnings.push_back(total_cost);
        }
        
        // Step 3: Sort max_earnings in descending order
        std::sort(max_earnings.begin(), max_earnings.end(), std::greater<int>());
        
        // Step 4: Take the top n earnings
        int max_revenue = 0;
        for (int i = 0; i < n && i < max_earnings.size(); ++i) {
            max_revenue += max_earnings[i];
        }
        
        return max_revenue;
    }
};


#endif
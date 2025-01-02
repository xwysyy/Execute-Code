#ifndef DEEPSEEK_CHAT_H
#define DEEPSEEK_CHAT_H
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int &n, int &k, std::vector<std::pair<int, int>> &b) {
        // Create a map to group bottles by their brand
        std::map<int, std::vector<int>> brandToCosts;
        for (const auto &bottle : b) {
            brandToCosts[bottle.first].push_back(bottle.second);
        }
        
        // For each brand, sort the costs in descending order
        for (auto &entry : brandToCosts) {
            std::sort(entry.second.rbegin(), entry.second.rend());
        }
        
        // Collect the top n costs from all brands
        std::vector<int> topCosts;
        for (auto &entry : brandToCosts) {
            for (int i = 0; i < entry.second.size() && i < n; ++i) {
                topCosts.push_back(entry.second[i]);
            }
        }
        
        // Sort the top costs in descending order
        std::sort(topCosts.rbegin(), topCosts.rend());
        
        // Sum the top n costs
        int total = 0;
        for (int i = 0; i < n && i < topCosts.size(); ++i) {
            total += topCosts[i];
        }
        
        return total;
    }
};


#endif